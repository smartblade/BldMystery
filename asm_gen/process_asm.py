
from optparse import OptionParser
import re
import time

parser = OptionParser()
parser.add_option("--show-hex-prefix", dest="show_hex_prefix",
                  help="show '0' prefix and 'h' suffix for hex numbers (yes, no)",
                  default="yes")
(options, args) = parser.parse_args()
options.show_hex_prefix = (options.show_hex_prefix != 'no')

num_regexp = re.compile('(?P<prefix>[^\w])(?P<number>[\dABCDEF]+)')
cmds = 'call|jmp|je|jne|jb|jnb|jbe|jl|jnl|jle|jg|ja|js|jns|jp|jnp|jo|jno|loop|loopnz'
direct_transfer_regexp = re.compile('^(?P<cmd>{})\s+(?P<target>[\dABCDEF]+)\W*$'.format(cmds))
external_ref_regexp = re.compile('(?P<extern>\w+\.\S+)')
byteReg = 'al|cl|dl'
wordReg = 'ax|cx|dx'
access = '\[.*\]'
regLeft = '((?P<byteLeft>{})|(?P<wordLeft>{}))'.format(byteReg, wordReg)
regRight = '((?P<byteRight>{})|(?P<wordRight>{}))'.format(byteReg, wordReg)
accessLeft = '(?P<accessLeft>{})'.format(access)
accessRight = '(?P<accessRight>{})'.format(access)
byte_memory_access_regexp = re.compile('^mov\s+(({},\s+{})|({},\s+{}))$'.format(regLeft, accessRight, accessLeft, regRight))

def toHex(n):
    return format(n, '08X')

def fromHex(h):
    return int(h, 16)

class CommentLine:
    _line = None
    def __init__(self, line):
        self._line = line

    def toString(self):
        return ";{}".format(self._line)

class MemoryInterval:
    def __init__(self, imageMap, addr, length):
        self._imageMap = imageMap
        self._addr = addr
        self._length = length

    def startAddress(self):
        return self._addr

    def endAddress(self):
        return self._addr + self._length

    def toString(self):
        line = ""
        curAddr = self._addr
        endAddr = self._addr + self._length
        while curAddr < endAddr:
            item = self._imageMap.itemsMap().get(curAddr)
            if item is not None:
                line += item.toString(self._imageMap)
                curAddr = item.endAddress()
            else:
                curAddr += 1
        return line

class DataItem:
    _addr = None
    _length = 0
    def __init__(self, mem, startAddr, endAddr):
        self._mem = mem
        self._addr = startAddr
        self._length = endAddr - startAddr
        self._ptrs = {}
        self._messages = {}

    def showLabel(self):
        pass

    def label(self):
        return "g{}".format(toHex(self._addr))

    def startAddress(self):
        return self._addr

    def endAddress(self):
        return self._addr + self._length

    def length(self):
        return self._length

    def applyRelocs(self, imageMap):
        reloc = imageMap.relocations()
        addr = self.startAddress()
        while addr < self.endAddress():
            if addr in reloc:
                targetAddr = reloc[addr]
                length = 4
                addrStr = ""
                for i in range(length, 0, -1):
                    addrStr += self._mem.bytes(addr + i - 1, addr + i)
                if (
                    fromHex(addrStr) != targetAddr or
                    (addr + length > self.endAddress())
                ):
                    self._messages[addr] = "Failed to apply reloc."
                else:
                    self._ptrs[addr] = targetAddr
                    imageMap.resolveAddress(targetAddr)
            else:
                length = 1
            addr += length

    def toString(self, imageMap):
        lines = ""
        addr = self.startAddress()
        while addr < self.endAddress():
            error = ""
            if addr in self._messages:
                error = "; {}".format(self._messages[addr])
            label = " " * 9
            if addr == self.startAddress():
                label = self.label()
            if addr in self._ptrs:
                length = 4
                dataSize = "dd"
                data = imageMap.label(self._ptrs[addr])
            else:
                length = 1
                dataSize = "db"
                data = "0{}h".format(self._mem.bytes(addr, addr + length))
            lines += "{}  {} {}{}\n".format(label, dataSize, data, error)
            addr += length
        return lines

class AsmInstruction:
    _addr = None
    _instr = None
    _length = 0
    _showLabel = False
    _message = ""
    def __init__(self, addr, instr, length):
        self._addr = addr
        self._instr = instr
        self._length = length
        self._pointers = []

    def showLabel(self):
        self._showLabel = True

    def label(self):
        return "l{}".format(toHex(self._addr))

    def startAddress(self):
        return self._addr

    def endAddress(self):
        return self._addr + self._length

    def length(self):
        return self._length

    def addHexPrefix(self, instr):
        return num_regexp.sub('\g<prefix>0\g<number>h', instr)

    def fixByteMemoryAccess(self):
        match = re.search(byte_memory_access_regexp, self._instr)
        if match:
            access = match.group('accessLeft') or match.group('accessRight')
            byte = match.group('byteLeft') or match.group('byteRight')
            word = match.group('wordLeft') or match.group('wordRight')
            size = None
            size = 'byte ptr' if byte is not None else size
            size = 'word ptr' if word is not None else size
            self._instr = self._instr.replace(access, '{} {}'.format(size, access))

    def applyRelocs(self, imageMap):
        reloc = imageMap.relocations()
        for a in range(self._addr, self._addr + self._length):
            if a in reloc:
                targetAddr = reloc[a]          
                if self._instr.find(toHex(targetAddr)) < 0:
                    self.printErrorMessage("Failed to apply reloc")
                else:
                    imageMap.resolveAddress(targetAddr)
                    self._pointers.append(targetAddr)

    def printErrorMessage(self, msg):
        self._message += " {}.".format(msg)

    def resolveDirectTransferAddress(self, imageMap):
        match = re.search(direct_transfer_regexp, self._instr)
        if match:
            cmd = match.group('cmd')
            targetAddr = fromHex(match.group('target'))
            label = imageMap.label(targetAddr)
            self._instr = "{} {}".format(cmd, label)
            imageMap.resolveAddress(targetAddr)

    def resolveExternalCalls(self, imageMap):
        match = re.search(external_ref_regexp, self._instr)
        if match:
            externalSym = match.group('extern')
            targetAddr = self.extractTargetAddress(imageMap)
            if targetAddr is None:
                targetAddr = 'external_symbol'
            self.printErrorMessage("[{}]".format(externalSym))
            self._instr = self._instr.replace(externalSym, targetAddr)

    def extractTargetAddress(self, imageMap):
        bytes = imageMap.bytes(self.startAddress(), self.endAddress())
        prefixes = [
            '(?P<directCall>E8)', # call ptr
            'FF15', # call [ptr]
            'FF25', # jmp [ptr]
            'A1', # mov eax, [ptr]
            '8B0D', # mov ecx, [ptr]
            '8B15', # mov edx, [ptr]
            '3B05', # cmp eax, [ptr]
            '3B0D', # cmp ecx, [ptr]
            '3B15', # cmp edx, [ptr]
        ]
        prefix = '|'.join(prefixes)
        match = re.search('^({})(?P<addr>........)$'.format(prefix), bytes)
        if match:
            addr = self.reverseAddressBytes(match.group('addr'))
            if match.group('directCall'):
                return toHex(self.endAddress() + fromHex(addr))
            else:
                return "[{}]".format(addr)
        return None

    def reverseAddressBytes(self, bytes):
        length = 4
        addr = ""
        for i in range(length, 0, -1):
            addr += bytes[2 * i - 2] + bytes[2 * i - 1]
        return addr

    def replacePointers(self, imageMap):
        instr = self._instr
        for addr in self._pointers:
            label = imageMap.label(addr)
            if instr.find("[{}]".format(toHex(addr))) < 0:
                label = "offset {}".format(label)
            (instr, count) = re.subn(toHex(addr), label, instr, 1)
            if count == 0:
                self.printErrorMessage("Failed to replace number with label")
        return instr

    def toString(self, imageMap):
        label = "{}:".format(self.label())
        if (not self._showLabel):
            label = "          "
        msg = ""
        if (self._message):
            msg = "; {}".format(self._message.lstrip())
        instr = self.replacePointers(imageMap)
        if options.show_hex_prefix:
            instr = self.addHexPrefix(instr)
        return "{} {}{}\n".format(label, instr, msg)

class ImageMap:
    def __init__(self, mem):
        self._mem = mem
        self._items = {}
        self._unresolvedAddresses = set()

    def itemsMap(self):
        return self._items

    def unresolvedAddresses(self):
        return self._unresolvedAddresses

    def relocations(self):
        return self._mem.relocations()

    def label(self, addr):
        if addr in self._items:
            return self._items[addr].label()
        return "l{}".format(toHex(addr))

    def add(self, addr, item):
        self._items[addr] = item

    def bytes(self, startAddress, endAddress):
        return self._mem.bytes(startAddress, endAddress)

    def dasm(self, addr):
        patterns = {
            "55" : "push ebp",
            "8BEC" : "mov ebp, esp",
        }
        length = 1
        instruction = "invalid {}".format(self._mem.bytes(addr, addr + length))
        for (pattern, instr) in patterns.items():
            l = len(pattern) / 2
            bytes = self._mem.bytes(addr, addr + l)
            if (bytes == pattern):
                instruction = instr
                length = l
                break
        return AsmInstruction(addr, instruction, length)

    def removeOverlappedItems(self):
        prevItem = None
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            if (prevItem is not None and prevItem.endAddress() > item.startAddress()):
                self._items[prevItem.startAddress()] = DataItem(self._mem, prevItem.startAddress(), item.startAddress())
            prevItem = item

    def mergeUserData(self, userMap):
        self._items = self._mergeUserData(self._items, userMap)

    def _mergeUserData(self, imageMap, userMap):
        result = dict()
        nextAddr = 0
        for addr in sorted(set(imageMap.keys() + userMap.keys())):
            item = imageMap.get(addr)
            usrItem = userMap.get(addr)
            if (usrItem != None):
                result[addr] = usrItem
                nextAddr = usrItem.endAddress()
            elif (item != None and item.endAddress() > nextAddr):
                if addr >= nextAddr:
                    result[addr] = item
                elif isinstance(item, AsmInstruction):
                    while nextAddr < item.endAddress():
                        result[nextAddr] = self.dasm(nextAddr)
                        nextAddr = result[nextAddr].endAddress()
        return result

    def splitDataItems(self):
        unresolvedAddresses = self._unresolvedAddresses
        curItem = None
        for addr in sorted(set(self._items.keys() + list(unresolvedAddresses))):
            item = self._items.get(addr)
            if (item != None):
                curItem = item
            elif isinstance(curItem, DataItem) and addr < curItem.endAddress():
                itemLeft = DataItem(self._mem, curItem.startAddress(), addr)
                itemRight = DataItem(self._mem, addr, curItem.endAddress())
                self._items[curItem.startAddress()] = itemLeft
                self._items[addr] = itemRight
                curItem = itemRight
        self._unresolvedAddresses -= set(self._items)

    def resolveAddress(self, addr):
        if addr in self._items:
            self._items[addr].showLabel()
        else:
            self._unresolvedAddresses.add(addr)

class MemoryArea:
    _addr = None
    _bytes = None
    _reloc = None
    def __init__(self, reloc):
        self._reloc = reloc

    def relocations(self):
        return self._reloc

    def addBytes(self, addr, bytes):
        if self._addr is None:
            self._addr = addr
            self._bytes = list(bytes)
        else:
            expectedSize = 2 * (addr - self._addr)
            delta = expectedSize - len(self._bytes)
            if (delta < 0):
                del self._bytes[delta]
            self._bytes.extend("0" * delta)
            self._bytes.extend(bytes)

    def bytes(self, startAddress, endAddress):
        curAddr = startAddress
        bytes = []
        while curAddr < endAddress:
            bytes.append(self._bytes[2 * (curAddr - self._addr)])
            bytes.append(self._bytes[2 * (curAddr - self._addr) + 1])
            curAddr += 1
        return "".join(bytes)

def removeOverlappedMemoryIntervals(imageMap, lineItems):
    prevIndex = -1
    for (i, lineItem) in enumerate(lineItems):
        if isinstance(lineItem, MemoryInterval):
            if (
                prevIndex > 0 and
                lineItems[prevIndex].endAddress() > lineItem.startAddress()
            ):
                startAddress = lineItems[prevIndex].startAddress()
                length = lineItem.startAddress() - startAddress
                lineItems[prevIndex] = MemoryInterval(
                    imageMap = imageMap,
                    addr = startAddress,
                    length = length)
            prevIndex = i

def readRelocations(relocFileName):
    addr_value_regexp = re.compile('^;;\s(?P<addr>0x[\dABCDEF]+)\s(?P<value>0x[\dABCDEF]+)')
    reloc = dict()
    f = open(relocFileName)
    for line in f.readlines():
        match = re.search(addr_value_regexp, line)
        if match:
            addr = match.group('addr')
            value = match.group('value')
            reloc[fromHex(addr)] = fromHex(value)
    f.close()
    return reloc

def readDataItems(dataFileName, mem):
    addr_inv_regexp = re.compile('^;;\s(?P<startAddr>0x[\dABCDEF]+)\s(?P<endAddr>0x[\dABCDEF]+)')
    dataItems = dict()
    f = open(dataFileName)
    for line in f.readlines():
        match = re.search(addr_inv_regexp, line)
        if match:
            startAddr = fromHex(match.group('startAddr'))
            endAddr = fromHex(match.group('endAddr'))
            dataItems[startAddr] = DataItem(mem, startAddr, endAddr)
    f.close()
    return dataItems

if __name__ == '__main__':
    start_time = time.time()
    f = open("Blade_patched.txt")
    lines = f.readlines()
    f.close()
    reloc = readRelocations("reloc.txt")
    mem = MemoryArea(reloc)
    userData = readDataItems("data.txt", mem)
    addr_label_regexp = re.compile('^(?P<addr>[\dABCDEF]+):\s+(?P<bytes>[\dABCDEF]+)\s+(?P<instr>\S.*)?$')
    print("Fill data structures...")
    lineItems = []
    imageMap = ImageMap(mem)
    for line in lines:
        match = re.search(addr_label_regexp, line)
        if not match:
            lineItems.append(CommentLine(line))
        else:
            addr = fromHex(match.group('addr'))
            instr = match.group('instr')
            bytes = match.group('bytes')
            length = len(bytes) / 2
            mem.addBytes(addr, bytes)
            memIntv = MemoryInterval(imageMap = imageMap, addr = addr, length = length)
            lineItems.append(memIntv)
            if instr is not None:
                item = AsmInstruction(addr, instr.rstrip(), length)
            else:
                item = DataItem(mem, addr, addr + length)
            imageMap.add(addr, item)
    print("Removing overlapped items...")
    removeOverlappedMemoryIntervals(imageMap, lineItems)
    imageMap.removeOverlappedItems()
    print("Merging user data...")
    imageMap.mergeUserData(userData)
    print("Processing data...")
    for imageItem in imageMap.itemsMap().values():
        if isinstance(imageItem, AsmInstruction):
            imageItem.resolveExternalCalls(imageMap)
            imageItem.applyRelocs(imageMap)
            imageItem.resolveDirectTransferAddress(imageMap)
    print("Splitting data items...")
    imageMap.splitDataItems()
    for imageItem in imageMap.itemsMap().values():
        if isinstance(imageItem, DataItem):
            imageItem.applyRelocs(imageMap)
    print("Writing data...")
    for imageItem in imageMap.itemsMap().values():
        if isinstance(imageItem, AsmInstruction):
            imageItem.fixByteMemoryAccess()
    f = open("Blade_patched_converted.txt", "wt")
    for lineItem in lineItems:
        f.write(lineItem.toString())
    f.write("; Unresolved addresses:\n")
    for addr in sorted(imageMap.unresolvedAddresses()):
        f.write("l{} dd 012345678h\n".format(toHex(addr)))
    f.close()
    print("Converted in %.2f seconds" % (time.time() - start_time))
