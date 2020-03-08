
from optparse import OptionParser
import os
import re
import time

parser = OptionParser()
parser.add_option("--show-hex-prefix", dest="show_hex_prefix",
                  help="show '0' prefix and 'h' suffix for hex numbers (yes, no)",
                  default="yes")
(options, args) = parser.parse_args()
options.show_hex_prefix = (options.show_hex_prefix != 'no')

entry_point_regexp = re.compile('Entry\s+Point:\s+(?P<entryPoint>[\dABCDEF]+)')
export_regexp = re.compile('\*\s+Export:\s+(?P<export>\S+),\s+(?P<ordinal>\d+)')
num_regexp = re.compile('(?P<prefix>[^\w\?\.@$])(?P<number>[\dABCDEF]+)')
cmds = 'call|jmp|je|jne|jb|jnb|jbe|jl|jnl|jle|jg|ja|js|jns|jp|jnp|jo|jno|loop|loopnz'
direct_transfer_regexp = re.compile('^(?P<cmd>{})\s+(?P<target>[\dABCDEF]+)\W*$'.format(cmds))
external_ref_regexp = re.compile('(?P<extern>\w+\.(?P<name>\S+))')
byteReg = 'al|cl|dl'
wordReg = 'ax|cx|dx'
dwordReg = 'eax|ecx|edx'
access = '\[.*\]'
regLeft = '((?P<byteLeft>{})|(?P<wordLeft>{})|(?P<dwordLeft>{}))'.format(byteReg, wordReg, dwordReg)
regRight = '((?P<byteRight>{})|(?P<wordRight>{})|(?P<dwordRight>{}))'.format(byteReg, wordReg, dwordReg)
accessLeft = '(?P<accessLeft>{})'.format(access)
accessRight = '(?P<accessRight>{})'.format(access)
byte_memory_access_regexp = re.compile('^mov\s+(({},\s+{})|({},\s+{}))$'.format(regLeft, accessRight, accessLeft, regRight))
noFWAIT = {
    'fstsw' : 'fnstsw',
}
fwait_regexp = re.compile('^(?P<cmd>{})'.format("|".join(noFWAIT.keys())))

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

class ImplementedProcedure:
    def __init__(self, startAddr, endAddr, label):
        self._startAddr = startAddr
        self._endAddr = endAddr
        self._label = label

    def label(self):
        return self._label

    def startAddress(self):
        return self._startAddr

    def endAddress(self):
        return self._endAddr

    def toString(self, imageMap):
        comment = 'Implemented in c++ code'
        return "{} call {}; {}\n".format(' ' * 10, self._label, comment)

class ImportReference:
    def __init__(self, addr, name):
        self._addr = addr
        self._name = name

    def showLabel(self, name):
        pass

    def label(self):
        return "__imp_{}".format(self._name)

    def startAddress(self):
        return self._addr

    def endAddress(self):
        return self._addr + self.length()

    def length(self):
        return 4

    def demangleStdcall(self):
        match = re.search('^_(?P<name>\w+)@(?P<size>\d+)$', self._name)
        if match:
            name = match.group('name')
            size = int(match.group('size'))
            return (name, size)
        return (None, None)

    def toString(self, imageMap):
        label = "g{}".format(toHex(self._addr))
        data = "0{}h".format(imageMap.bytes(self._addr, self.endAddress()))
        return "{}  dd {}; {}\n".format(label, data, self._name)

class DataItem:
    _addr = None
    _length = 0
    def __init__(self, startAddr, endAddr):
        self._addr = startAddr
        self._length = endAddr - startAddr
        self._ptrs = {}
        self._messages = {}

    def showLabel(self, name):
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
                addrStr = reverseBytes(imageMap.bytes(addr, addr + length))
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

    def canRead32Bit(self, imageMap, addr):
        length = 4
        if addr + length > self.endAddress():
            return False
        for i in range(addr, addr + length):
            if i in self._ptrs:
                return False
            if imageMap.isUninitialisedByte(i):
                return False
        return True

    def zeroFilledDataLen(self, imageMap, startAddr):
        curAddr = startAddr
        while curAddr < self.endAddress():
            if imageMap.bytes(curAddr, curAddr + 1) != "00":
                break
            if curAddr in self._ptrs:
                break
            curAddr += 1
        return (curAddr - startAddr)

    def uninitialisedDataLen(self, imageMap, startAddr):
        curAddr = startAddr
        while curAddr < self.endAddress():
            if not imageMap.isUninitialisedByte(curAddr):
                break
            curAddr += 1
        return (curAddr - startAddr)

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
            elif self.uninitialisedDataLen(imageMap, addr) > 0:
                length = self.uninitialisedDataLen(imageMap, addr)
                if length < 4:
                    dataSize = "db"
                    numElements = length
                else:
                    dataSize = "dd"
                    numElements = length / 4
                    length = numElements * 4
                data = "{} dup (?)".format(numElements)
            elif self.zeroFilledDataLen(imageMap, addr) >= 8:
                numElements = self.zeroFilledDataLen(imageMap, addr) / 4
                length = numElements * 4
                dataSize = "dd"
                data = "{} dup (0)".format(numElements)
            elif self.canRead32Bit(imageMap, addr):
                length = 4
                dataSize = "dd"
                num = reverseBytes(imageMap.bytes(addr, addr + length))
                data = "0{}h".format(num)
            else:
                length = 1
                dataSize = "db"
                data = "0{}h".format(imageMap.bytes(addr, addr + length))
            lines += "{}  {} {}{}\n".format(label, dataSize, data, error)
            addr += length
        return lines

class AsmInstruction:
    _addr = None
    _instr = None
    _length = 0
    _showLabel = False
    _name = None
    _message = ""
    def __init__(self, addr, instr, length):
        self._addr = addr
        self._instr = instr
        self._length = length
        self._pointers = []

    def showLabel(self, name):
        self._showLabel = True
        self._name = name

    def hideLabel(self):
        self._showLabel = False

    def label(self):
        return self._name or "l{}".format(toHex(self._addr))

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
            dword = match.group('dwordLeft') or match.group('dwordRight')
            size = None
            size = 'byte ptr' if byte is not None else size
            size = 'word ptr' if word is not None else size
            size = 'dword ptr' if dword is not None else size
            self._instr = self._instr.replace(access, '{} {}'.format(size, access))

    def addNearJumpModifier(self, imageMap):
        opcode = imageMap.bytes(self._addr, self._addr + 1)
        if opcode == "E9":
            self._instr = self._instr.replace('jmp', 'jmp near ptr')

    def avoidEmittingOfFWAIT(self):
        match = re.search(fwait_regexp, self._instr)
        if match:
            cmd = match.group('cmd')
            self._instr = self._instr.replace(cmd, noFWAIT[cmd])

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
            symbolName = match.group('name')
            (targetAddr, isDirectCall) = self.extractTargetAddress(imageMap)
            if targetAddr is not None and not isDirectCall:
                imageMap.addImportReference(targetAddr, symbolName)
            self.printErrorMessage("[{}]".format(externalSym))
            target = self.buildTargetOperand(targetAddr, isDirectCall)
            self._instr = self._instr.replace(externalSym, target)

    def buildTargetOperand(self, targetAddr, isDirectCall):
        if targetAddr is None:
            return 'external_symbol'
        elif isDirectCall:
            return toHex(targetAddr)
        else:
            return "[{}]".format(toHex(targetAddr))

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
            addr = reverseBytes(match.group('addr'))
            if match.group('directCall'):
                return (self.endAddress() + fromHex(addr), True)
            else:
                return (fromHex(addr), False)
        return (None, False)

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

    def isReturn(self):
        return self._instr.startswith("ret")

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
        self._importReferences = {}
        self._exports = {}
        self._unresolvedAddresses = set()

    def itemsMap(self):
        return self._items

    def unresolvedAddresses(self):
        return self._unresolvedAddresses

    def relocations(self):
        return self._mem.relocations()

    def importReferences(self):
        importReferences = []
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            if (isinstance(item, ImportReference)):
                importReferences.append(item)
        return importReferences

    def exports(self):
        return self._exports

    def label(self, addr):
        if addr in self._items:
            return self._items[addr].label()
        return "l{}".format(toHex(addr))

    def add(self, addr, item):
        self._items[addr] = item

    def addImportReference(self, addr, name):
        self._importReferences[addr] = ImportReference(addr, name)

    def addExport(self, addr, name):
        self._exports[addr] = name
        self.resolveAddress(addr)

    def bytes(self, startAddress, endAddress):
        return self._mem.bytes(startAddress, endAddress)

    def isUninitialisedByte(self, address):
        return self._mem.isUninitialisedByte(address)

    def dasm(self, addr):
        patterns = {
            "55" : "push ebp",
            "56" : "push esi",
            "57" : "push edi",
            "8BEC" : "mov ebp, esp",
            "83EC4C" : "sub esp, 0000004C",
            "81EC44040000" : "sub esp, 00000444",
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
                self._items[prevItem.startAddress()] = DataItem(prevItem.startAddress(), item.startAddress())
            prevItem = item

    def isInvalidInstruction(self, item, relAddr):
        relLength = 4
        relStart = relAddr
        relEnd = relAddr + relLength
        return relAddr < item.startAddress() or relEnd > item.endAddress()

    def removeInvalidInstructions(self):
        invalidInstructions = set()
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            if isinstance(item, AsmInstruction):
                for relAddr in range(item.startAddress(), item.endAddress()):
                    if (relAddr in self.relocations()):
                        if self.isInvalidInstruction(item, relAddr):
                            invalidInstructions.add(item)
        relLength = 4
        for relAddr in sorted(self.relocations().keys()):
            for addr in range(relAddr, relAddr + relLength):
                item = self._items.get(addr)
                if isinstance(item, AsmInstruction):
                        if self.isInvalidInstruction(item, relAddr):
                            invalidInstructions.add(item)
        for item in invalidInstructions:
            startAddr = item.startAddress()
            endAddr = item.endAddress()
            self._items[startAddr] = DataItem(startAddr, endAddr)

    def endAddressOfAdjacentDataItems(self, addr):
        item = self._items[addr]
        if not isinstance(item, DataItem):
            return item.startAddress()
        nextItem = self._items.get(item.endAddress())
        while isinstance(nextItem, DataItem):
            item = nextItem
            nextItem = self._items.get(item.endAddress())
        return item.endAddress()

    def mergeAdjacentDataItems(self):
        endAddr = None
        for addr in sorted(self._items.keys()):
            if endAddr is not None and addr < endAddr:
                del self._items[addr]
            else:
                endAddr = self.endAddressOfAdjacentDataItems(addr)
                if (endAddr > self._items[addr].endAddress()):
                    self._items[addr] = DataItem(addr, endAddr)

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
        importReferences = self._importReferences.values()
        addresses = (
            self._items.keys() +
            list(unresolvedAddresses) +
            self.relocations().values() +
            map(lambda ref : ref.startAddress(), importReferences) +
            map(lambda ref : ref.endAddress(), importReferences)
        )
        curItem = None
        for addr in sorted(set(addresses)):
            item = self._items.get(addr)
            if (item != None):
                curItem = item
            elif isinstance(curItem, DataItem) and addr < curItem.endAddress():
                itemLeft = DataItem(curItem.startAddress(), addr)
                itemRight = DataItem(addr, curItem.endAddress())
                self._items[curItem.startAddress()] = itemLeft
                self._items[addr] = itemRight
                curItem = itemRight
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            importRef = self._importReferences.get(addr)
            if (importRef is not None and
                isinstance(item, DataItem) and
                item.endAddress() == importRef.endAddress()
            ):
                self._items[addr] = importRef
        self._unresolvedAddresses -= set(self._items)

    def resolveAddress(self, addr, name = None):
        if addr in self._items:
            self._items[addr].showLabel(name)
        else:
            self._unresolvedAddresses.add(addr)

    def removeImplementedProcedure(self, addr):
        label = self.label(addr)
        item = self._items[addr]
        while True:
            del self._items[item.startAddress()]
            if (item.isReturn()):
                break;
            item = self._items[item.endAddress()]
        endAddress = item.endAddress()
        # remove jump tables for switch statements
        item = self._items.get(item.endAddress())
        while isinstance(item, DataItem):
            del self._items[item.startAddress()]
            endAddress = item.endAddress()
            item = self._items[item.endAddress()]
        self._items[addr] = ImplementedProcedure(addr, endAddress, label)

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
            for i in range(delta):
                self._bytes.append(None)
            self._bytes.extend(bytes)

    def bytes(self, startAddress, endAddress):
        curAddr = startAddress
        bytes = []
        while curAddr < endAddress:
            index = 2 * (curAddr - self._addr)
            if index < len(self._bytes):
                bytes.append(self._bytes[index] or "?")
                bytes.append(self._bytes[index + 1] or "?")
            else:
                bytes.append("?")
                bytes.append("?")
            curAddr += 1
        return "".join(bytes)

    def isUninitialisedByte(self, address):
        index = 2 * (address - self._addr)
        if index >= len(self._bytes):
            return True
        return self._bytes[index] is None and self._bytes[index + 1] is None

def extractEntryPoint(line):
    match = re.search(entry_point_regexp, line)
    if match:
        return fromHex(match.group('entryPoint'))
    return None

def extractExport(line):
    match = re.search(export_regexp, line)
    if match:
        return match.group('export')
    return None

def makeMemoryIntervalsAdjacent(imageMap, lineItems):
    prevIndex = -1
    for (i, lineItem) in enumerate(lineItems):
        if isinstance(lineItem, MemoryInterval):
            if (
                prevIndex > 0 and
                lineItems[prevIndex].endAddress() != lineItem.startAddress()
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

def readDataItems(dataFileName):
    addr_inv_regexp = re.compile('^;;\s(?P<startAddr>0x[\dABCDEF]+)\s(?P<endAddr>0x[\dABCDEF]+)')
    dataItems = dict()
    f = open(dataFileName)
    for line in f.readlines():
        match = re.search(addr_inv_regexp, line)
        if match:
            startAddr = fromHex(match.group('startAddr'))
            endAddr = fromHex(match.group('endAddr'))
            dataItems[startAddr] = DataItem(startAddr, endAddr)
    f.close()
    return dataItems

def reverseBytes(bytes):
    length = len(bytes) / 2
    num = ""
    for i in range(length, 0, -1):
        num += bytes[2 * i - 2] + bytes[2 * i - 1]
    return num

def stdcallPrototype(name, size):
    if size != 0:
        params = "Params{} params".format(size)
    else:
        params = ""
    return "void __stdcall {}({})".format(name, params)

def writeUninitialisedData(imageMap, endDataAdddress):
    f = open("uninitialised.asm", "wt")
    for addr in sorted(imageMap.itemsMap().keys()):
        imageItem = imageMap.itemsMap()[addr]
        if imageItem.startAddress() >= endDataAdddress:
            f.write(imageItem.toString(imageMap))
    f.close()


def writeStdcallFunctions(importReferences):
    f = open("stdcallDefs.cpp", "wt")
    stdcalls = []
    sizes = set()
    for impref in importReferences:
        (name, size) = impref.demangleStdcall()
        if name is not None:
            stdcalls.append((name, size))
            if size != 0:
                sizes.add(size)
    f.write('\nextern "C" {\n\n')
    for size in sizes:
        fields = "    char params[{}];\n".format(size)
        name = "Params{}".format(size)
        strucureDef = "typedef struct\n{{\n{}}} {};\n\n".format(fields, name)
        f.write(strucureDef)
    for (name, size) in stdcalls:
        decl = "__declspec(dllexport) {};".format(stdcallPrototype(name, size))
        f.write("{}\n".format(decl))
    f.write('\n}/* extern "C" */\n')
    for (name, size) in stdcalls:
        definition = "{}\n{{\n}}\n".format(stdcallPrototype(name, size))
        f.write("\n{}".format(definition))
    f.close()

def writeExportDeclarations(imageMap):
    f = open("export.inc", "wt")
    for addr in sorted(imageMap.exports().keys()):
        f.write("public {}\n".format(imageMap.label(addr)))
    f.close()

def isCdeclMangling(exportName, internalName):
    return (internalName == '_' + exportName)

def writeExportCmd(imageMap, mangledNames, implementedProcedures):
    f = open("export_cmd.txt", "wt")
    exportAddrs = set(imageMap.exports().keys()) - set(implementedProcedures)
    for addr in sorted(exportAddrs):
        exportName = imageMap.exports()[addr]
        internalName = imageMap.label(addr)
        if addr in mangledNames:
            internalName = mangledNames[addr]
        if isCdeclMangling(exportName, internalName):
            symbolName = "{}".format(exportName)
        else:
            symbolName = "{}={}".format(exportName, internalName)
        f.write("/EXPORT:{}\n".format(symbolName))
    f.close()

def collectProceduresFromFile(fileName):
    mangledNames = {}
    nativeProcedures = set()
    f = open(fileName)
    lines = f.readlines()
    addr_regexp = re.compile('Entry\s+point:\s+0x(?P<addr>[\dABCDEF]+)')
    mangling_regexp = re.compile('VC\+\+\s+mangling:\s+(?P<mangling>[\S]+)')
    proc_regexp = re.compile('\W(?P<proc>\w+)\s*\([^\(\)]*\)\s*\{')
    meta = False
    addr = None
    for line in lines:
        if line.find("/*") >= 0:
            meta = True
            addr = None
            mangling = None
        if line.find("*/") >= 0:
            meta = False
            definition = ""
            if addr is not None:
                mangledNames[addr] = mangling
        if line.find("BLD_NATIVE") >= 0:
            nativeProcedures.add(addr)
        if meta:
            match = re.search(addr_regexp, line)
            if match:
                addr = fromHex(match.group('addr'))
            match = re.search(mangling_regexp, line)
            if match:
                mangling = match.group('mangling')
        elif addr is not None and mangledNames[addr] is None:
            definition += line
            if line.find("{") >= 0:
                cdecl_mangling = None
                match = re.search(proc_regexp, definition)
                if match:
                    proc_name = match.group('proc')
                    cdecl_mangling = "_{}".format(proc_name)
                fallback = "fn{}".format(toHex(addr))
                mangledNames[addr] = cdecl_mangling or fallback
    f.close()
    return (mangledNames, set(mangledNames.keys()) - nativeProcedures)

def collectVariablesFromFile(fileName):
    varNames = {}
    f = open(fileName)
    lines = f.readlines()
    addr_regexp = re.compile('Data\s+address:\s+0x(?P<addr>[\dABCDEF]+)')
    name_regexp = re.compile('(\W+(?P<name>\w+)(\s*\[\s*\d*\s*\])*\s*)?;')
    addr = None
    for line in lines:
        match = re.search(addr_regexp, line)
        if match:
            addr = fromHex(match.group('addr'))
        if addr is not None:
            match = re.search(name_regexp, line)
            if match:
                varNames[addr] = match.group('name')
                addr = None
    f.close()
    return varNames

def collectSymbolsFromSources():
    varNames = {}
    mangledNames = {}
    implementedProcedures = []
    for (root, dirs, files) in os.walk('..'):
        for file in files:
            if file.endswith(".cpp") or file.endswith(".h"):
                fileName = os.path.join(root, file)
                (names, implemented) = collectProceduresFromFile(fileName)
                mangledNames.update(names)
                implementedProcedures += implemented
                varNames.update(collectVariablesFromFile(fileName))
    return (varNames, mangledNames, implementedProcedures)

if __name__ == '__main__':
    start_time = time.time()
    f = open("raw.txt")
    lines = f.readlines()
    f.close()
    reloc = readRelocations("reloc.txt")
    userData = readDataItems("data.txt")
    addr_label_regexp = re.compile('^(?P<addr>[\dABCDEF]+):\s+(?P<bytes>[\dABCDEF]+)\s+(?P<instr>\S.*)?$')
    print("Fill data structures...")
    entryPoint = None
    export = None
    lineItems = []
    mem = MemoryArea(reloc)
    imageMap = ImageMap(mem)
    for line in lines:
        match = re.search(addr_label_regexp, line)
        if not match:
            lineItems.append(CommentLine(line))
            entryPoint = entryPoint or extractEntryPoint(line)
            export = export or extractExport(line)
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
                item = DataItem(addr, addr + length)
            imageMap.add(addr, item)
            if export is not None:
                imageMap.addExport(addr, export)
                export = None
    imageMap.resolveAddress(entryPoint, '__startup')
    print("Removing overlapped items...")
    makeMemoryIntervalsAdjacent(imageMap, lineItems)
    imageMap.removeOverlappedItems()
    print("Merging user data...")
    imageMap.mergeUserData(userData)
    print("Removing invalid instructions...")
    imageMap.removeInvalidInstructions()
    print("Merge adjacent data iiems...")
    imageMap.mergeAdjacentDataItems()
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
    print("Collect symbols from sources...")
    (varNames, mangledNames, implementedProcedures) = collectSymbolsFromSources()
    print("Hide implemented procedures...")
    for addr in implementedProcedures:
        imageMap.removeImplementedProcedure(addr)
    print("Writing data...")
    for imageItem in imageMap.itemsMap().values():
        if isinstance(imageItem, AsmInstruction):
            imageItem.fixByteMemoryAccess()
            imageItem.addNearJumpModifier(imageMap)
            imageItem.avoidEmittingOfFWAIT()
    f = open("native.asm", "wt")
    for lineItem in lineItems:
        f.write(lineItem.toString())
    f.write("; Unresolved addresses:\n")
    for addr in sorted(imageMap.unresolvedAddresses()):
        f.write("l{} dd 012345678h\n".format(toHex(addr)))
    f.close()
    writeUninitialisedData(imageMap, lineItems[-1].endAddress())
    f = open("import.inc", "wt")
    for impref in imageMap.importReferences():
        f.write("externdef {}: ptr\n".format(impref.label()))
    f.close()
    writeExportDeclarations(imageMap)
    writeExportCmd(imageMap, mangledNames, implementedProcedures)
    writeStdcallFunctions(imageMap.importReferences())
    f = open("procedures.inc", "wt")
    for addr in sorted(mangledNames.keys()):
        name = mangledNames[addr]
        label = imageMap.label(addr)
        f.write("externdef {}: near\n{} equ {}\n".format(name, label, name))
    f.close()
    f = open("variables.inc", "wt")
    for addr in sorted(varNames.keys()):
        name = varNames[addr]
        label = imageMap.label(addr)
        f.write("public _{}\n{} equ _{}\n".format(name, label, name))
    f.close()
    print("Converted in %.2f seconds" % (time.time() - start_time))
