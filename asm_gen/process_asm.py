
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

def toHex(n):
    return format(n, '08X')

def fromHex(h):
    return int(h, 16)

def resolveAddress(addr, instrMap, unresolvedAddresses):
    if addr in instrMap:
        instrMap[addr].showLabel()
    else:
        unresolvedAddresses.add(addr)

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

    def toString(self):
        line = ""
        curAddr = self._addr
        endAddr = self._addr + self._length
        while curAddr < endAddr:
            item = self._imageMap.itemsMap().get(curAddr)
            if item is not None:
                line += item.toString()
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

    def showLabel(self):
        pass

    def startAddress(self):
        return self._addr

    def endAddress(self):
        return self._addr + self._length

    def length(self):
        return self._length

    def toString(self):
        bytes = mem.bytes(self.startAddress(), self.endAddress())
        startAddr = toHex(self.startAddress())
        endAddr = toHex(self.endAddress())
        return ";{}-{}\n;{}{}\n;\n".format(startAddr, endAddr, " " * 10, bytes)

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

    def showLabel(self):
        self._showLabel = True

    def endAddress(self):
        return self._addr + self._length

    def length(self):
        return self._length

    def addHexPrefix(self):
        self._instr = num_regexp.sub('\g<prefix>0\g<number>h', self._instr)

    def applyRelocs(self, reloc, instrMap, unresolvedAddresses):
        for a in range(self._addr, self._addr + self._length):
            if a in reloc:
                targetAddr = fromHex(reloc[a])
                label = "l{}".format(toHex(targetAddr))
                if self._instr.find("[{}]".format(toHex(targetAddr))) < 0:
                    label = "offset {}".format(label)
                (self._instr, count) = re.subn(toHex(targetAddr), label, self._instr, 1)
                if count == 0:
                    self.printErrorMessage("Failed to apply reloc")
                else:
                    resolveAddress(targetAddr, instrMap, unresolvedAddresses)

    def printErrorMessage(self, msg):
        self._message += " {}.".format(msg)

    def resolveDirectTransferAddress(self, instrMap, unresolvedAddresses):
        match = re.search(direct_transfer_regexp, self._instr)
        if match:
            cmd = match.group('cmd')
            targetAddr = fromHex(match.group('target'))
            label = "l{}".format(toHex(targetAddr))
            self._instr = "{} {}".format(cmd, label)
            resolveAddress(targetAddr, instrMap, unresolvedAddresses)

    def resolveExternalCalls(self):
        match = re.search(external_ref_regexp, self._instr)
        if match:
            target = match.group('extern')
            # TODO keep external symbol name
            self._instr = self._instr.replace(target, 'external_symbol')

    def toString(self):
        label = "l{}:".format(toHex(self._addr))
        if (not self._showLabel):
            label = "          "
        msg = ""
        if (self._message):
            msg = "; {}".format(self._message.lstrip())
        return "{} {}{}\n".format(label, self._instr, msg)

class ImageMap:
    def __init__(self, mem):
        self._mem = mem
        self._items = {}

    def itemsMap(self):
        return self._items

    def add(self, addr, item):
        self._items[addr] = item

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

    def splitDataItems(self, unresolvedAddresses):
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

class MemoryArea:
    _addr = None
    _bytes = None
    def addBytes(self, addr, bytes):
        if self._addr is None:
            self._addr = addr
            self._bytes = list(bytes)
        else:
            expectedSize = 2 * (addr - self._addr)
            delta = expectedSize - len(self._bytes)
            if (delta < 0):
                del self._bytes[delta]
            self._bytes.extend(" " * delta)
            self._bytes.extend(bytes)

    def bytes(self, startAddress, endAddress):
        curAddr = startAddress
        bytes = []
        while curAddr < endAddress:
            bytes.append(self._bytes[2 * (curAddr - self._addr)])
            bytes.append(self._bytes[2 * (curAddr - self._addr) + 1])
            curAddr += 1
        return "".join(bytes)

def readRelocations(relocFileName):
    addr_value_regexp = re.compile('^;;\s(?P<addr>0x[\dABCDEF]+)\s(?P<value>0x[\dABCDEF]+)')
    reloc = dict()
    f = open(relocFileName)
    for line in f.readlines():
        match = re.search(addr_value_regexp, line)
        if match:
            addr = match.group('addr')
            value = match.group('value')
            reloc[fromHex(addr)] = value
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
    mem = MemoryArea()
    reloc = readRelocations("reloc.txt")
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
    print("Merging user data...")
    imageMap.mergeUserData(userData)
    print("Processing data...")
    unresolvedAddresses = set()
    for imageItem in imageMap.itemsMap().values():
        if isinstance(imageItem, AsmInstruction):
            imageItem.resolveExternalCalls()
            imageItem.applyRelocs(reloc, imageMap.itemsMap(), unresolvedAddresses)
            imageItem.resolveDirectTransferAddress(imageMap.itemsMap(), unresolvedAddresses)
    print("Splitting data items...")
    imageMap.splitDataItems(unresolvedAddresses)
    unresolvedAddresses = unresolvedAddresses - set(imageMap.itemsMap())
    print("Writing data...")
    if options.show_hex_prefix:
        for imageItem in imageMap.itemsMap().values():
            if isinstance(imageItem, AsmInstruction):
                imageItem.addHexPrefix()
    f = open("Blade_patched_converted.txt", "wt")
    for lineItem in lineItems:
        f.write(lineItem.toString())
    f.write("; Unresolved addresses:\n")
    for addr in sorted(unresolvedAddresses):
        f.write("l{} dd 012345678h\n".format(toHex(addr)))
    f.write("external_symbol dd 012345678h\n")
    f.close()
    print("Converted in %.2f seconds" % (time.time() - start_time))
