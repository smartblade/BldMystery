import hashlib
import json
from optparse import OptionParser
import os
import pathlib
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
jump_cmds = 'jmp|je|jne|jb|jnb|jbe|jl|jnl|jle|jg|ja|js|jns|jp|jnp|jo|jno'
cmds = 'call|loop|loopnz|' + jump_cmds
direct_transfer = '^(?P<cmd>{})\s+(?P<target>[\dABCDEF]+)\W*$'
direct_transfer_regexp = re.compile(direct_transfer.format(cmds))
jump_regexp = re.compile(direct_transfer.format(jump_cmds))
external_ref_regexp = re.compile('(?P<extern>(?P<library>\w+)\.(?P<name>\S+))')
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

class ImageWriter:
    def __init__(self, imageMap):
        self._imageMap = imageMap
        self._lines = []
        self._printedComments = set()
        self._items = []

    def imageMap(self):
        return self._imageMap

    def label(self, addr):
        for item in self._items:
            if hasattr(item, 'labelAt') and item.labelAt(addr) != None:
                return item.labelAt(addr)
        return self._imageMap.label(addr)

    def write(self, item):
        if isinstance(item, str):
            self._lines.append(item)
        else:
            self._items.append(item)
            if not item.startAddress() in self._printedComments:
                comments = self._imageMap.commentsToString(item.startAddress())
                self._lines.append(comments)
                self._printedComments.add(item.startAddress())
            item.write(self)
            self._items.pop()

    def toString(self):
        return ''.join(self._lines)

class CodeItem:
    def adjustInstructions(self, imageMap):
        pass

class Procedure(CodeItem):
    def __init__(self, items, isUsed):
        self._firstItem = items[0]
        self._lastItem = items[-1]
        self._items = {item.startAddress(): item for item in items}
        self._isUsed = isUsed

    def label(self):
        return self._firstItem.label()

    def startAddress(self):
        return self._firstItem.startAddress()

    def endAddress(self):
        return self._lastItem.endAddress()

    def adjustInstructions(self, imageMap):
        for item in self._items.values():
            if isinstance(item, CodeItem):
                item.adjustInstructions(imageMap)

    def labelAt(self, addr):
        item = self._items.get(addr)
        if item is not None:
            return item.label()
        return None

    def _writeItems(self, writer):
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            writer.write(item)

    def write(self, writer):
        if not self._isUsed:
            self._writeItems(writer)
            return
        self._firstItem.hideLabel()
        writer.write("{} PROC\n".format(self.label()))
        self._writeItems(writer)
        writer.write("{} ENDP\n".format(self.label()))

class ImportReference:
    def __init__(self, addr, library, name):
        is_underscore = (library == 'python15')
        self._addr = addr
        self._name = name
        if is_underscore:
            self._mangled_name = "_{}".format(name)
        else:
            self._mangled_name = name

    def showLabel(self, name):
        pass

    def label(self):
        return "__imp_{}".format(self._mangled_name)

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

    def write(self, writer):
        imageMap = writer.imageMap()
        label = "g{}".format(toHex(self._addr))
        data = "0{}h".format(imageMap.bytes(self._addr, self.endAddress()))
        writer.write("{}  dd {}; {}\n".format(label, data, self._name))

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

    def write(self, writer):
        imageMap = writer.imageMap()
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
                data = writer.label(self._ptrs[addr])
            elif self.uninitialisedDataLen(imageMap, addr) > 0:
                length = self.uninitialisedDataLen(imageMap, addr)
                if length < 4:
                    dataSize = "db"
                    numElements = length
                else:
                    dataSize = "dd"
                    numElements = length // 4
                    length = numElements * 4
                data = "{} dup (?)".format(numElements)
            elif self.zeroFilledDataLen(imageMap, addr) >= 8:
                numElements = self.zeroFilledDataLen(imageMap, addr) // 4
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
            writer.write("{}  {} {}{}\n".format(label, dataSize, data, error))
            addr += length

class AsmInstruction(CodeItem):
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
        self._parseJump()

    def showLabel(self, name):
        self._showLabel = True
        self._name = name

    def hideLabel(self):
        self._showLabel = False

    def hasLabel(self):
        return self._showLabel

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
            library = match.group('library')
            symbolName = match.group('name')
            (targetAddr, isDirectCall) = self.extractTargetAddress(imageMap)
            if targetAddr is not None and not isDirectCall:
                imageMap.addImportReference(targetAddr, library, symbolName)
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

    def replacePointers(self, writer):
        instr = self._instr
        for addr in self._pointers:
            label = writer.label(addr)
            if instr.find("[{}]".format(toHex(addr))) < 0:
                label = "offset {}".format(label)
            (instr, count) = re.subn(toHex(addr), label, instr, 1)
            if count == 0:
                self.printErrorMessage("Failed to replace number with label")
        return instr

    def isReturn(self):
        return self._instr.startswith("ret")

    def isUnconditionalJump(self):
        return self._instr.startswith("jmp")

    def isShortJump(self, imageMap):
        if self.isUnconditionalJump():
            opcode = imageMap.bytes(self._addr, self._addr + 1)
            if opcode == "E9":
                return False
        return True

    def _parseJump(self):
        match = re.search(jump_regexp, self._instr)
        if match:
            self._isJump = True
            self._jumpTarget = fromHex(match.group('target'))
        else:
            self._isJump = False
            self._jumpTarget = None

    def isJump(self):
        return self._isJump or self.isUnconditionalJump()

    def jumpTarget(self):
        return self._jumpTarget

    def write(self, writer):
        label = "{}:".format(self.label())
        if (not self._showLabel):
            label = "          "
        msg = ""
        if (self._message):
            msg = "; {}".format(self._message.lstrip())
        instr = self.replacePointers(writer)
        if options.show_hex_prefix:
            instr = self.addHexPrefix(instr)
        writer.write("{} {}{}\n".format(label, instr, msg))

class CodeBlock(CodeItem):
    def __init__(self, instructions):
        self._instructions = instructions

    def showLabel(self, name):
        self._instructions[0].showLabel(name)

    def hideLabel(self):
        self._instructions[0].hideLabel()

    def hasLabel(self):
        return self._instructions[0].hasLabel()

    def label(self):
        return self._instructions[0].label()

    def startAddress(self):
        return self._instructions[0].startAddress()

    def endAddress(self):
        return self._instructions[-1].endAddress()

    def length(self):
        return self.endAddress() - self.startAddress()

    def isReturn(self):
        return self._instructions[-1].isReturn()

    def isUnconditionalJump(self):
        return self._instructions[-1].isUnconditionalJump()

    def isShortJump(self, imageMap):
        return self._instructions[-1].isShortJump(imageMap)

    def jumpTarget(self):
        return self._instructions[-1].jumpTarget()

    def split(self, addr):
        instructions1 = []
        instructions2 = []
        for instr in self._instructions:
            if instr.startAddress() < addr:
                instructions1.append(instr)
            else:
                instructions2.append(instr)
        if (len(instructions2) == 0 or instructions2[0].startAddress() != addr):
            return (None, None)
        return (instructions1, instructions2)

    def processData(self, imageMap):
        for instr in self._instructions:
            instr.resolveExternalCalls(imageMap)
            instr.applyRelocs(imageMap)
            instr.resolveDirectTransferAddress(imageMap)

    def adjustInstructions(self, imageMap):
        for instr in self._instructions:
            instr.fixByteMemoryAccess()
            instr.addNearJumpModifier(imageMap)
            instr.avoidEmittingOfFWAIT()

    def write(self, writer):
        for instr in self._instructions:
            writer.write(instr)

class ImageMap:
    def __init__(self, mem):
        self._mem = mem
        self._items = {}
        self._blocks = {}
        self._importReferences = {}
        self._exports = {}
        self._unresolvedAddresses = set()
        self._comments = {}

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

    def addImportReference(self, addr, library, name):
        self._importReferences[addr] = ImportReference(addr, library, name)

    def addExport(self, addr, name):
        self._exports[addr] = name
        self.resolveAddress(addr)

    def addComments(self, addr, comments):
        if (len(comments) > 0):
            self._comments[addr] = comments

    def comments(self, addr):
        return self._comments.get(addr)

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
            l = len(pattern) // 2
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
        for addr in sorted(set(list(imageMap) + list(userMap))):
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
            list(self._items) +
            list(unresolvedAddresses) +
            list(self.relocations().values()) +
            list(map(lambda ref : ref.startAddress(), importReferences)) +
            list(map(lambda ref : ref.endAddress(), importReferences))
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
        if addr in self._items or self.splitBlock(addr):
            self._items[addr].showLabel(name)
        else:
            self._unresolvedAddresses.add(addr)

    def splitBlock(self, addr):
        block = self._blocks.get(addr)
        if block is None:
            return False
        (instrs1, instrs2) =  block.split(addr)
        if instrs1 is None or instrs2 is None:
            return False
        del self._items[block.startAddress()]
        self._createBlock(instrs1)
        self._createBlock(instrs2)
        return True

    def _createBlock(self, instructions):
        block = CodeBlock(instructions)
        self._items[block.startAddress()] = block
        for instr in instructions:
            self._blocks[instr.startAddress()] = block

    def makeBlocks(self):
        blockInstructions = []
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            if (
                len(blockInstructions) > 0 and
                (
                    not isinstance(item, AsmInstruction) or
                    item.hasLabel() or
                    blockInstructions[-1].endAddress() != item.startAddress() or
                    blockInstructions[-1].isReturn() or
                    blockInstructions[-1].isJump())
            ):
                for blockInstruction in blockInstructions:
                    del self._items[blockInstruction.startAddress()]
                self._createBlock(blockInstructions)
                blockInstructions = []
            if isinstance(item, AsmInstruction):
                blockInstructions.append(item)

    def _tryMakeProcedure(self, addr, shortJumpsFrom, isUsed):
        items = []
        item = self._items[addr]
        if item.isUnconditionalJump() and item.jumpTarget() is None:
            return
        while True:
            items.append(item)
            if not isinstance(item, CodeBlock):
                return
            if (item.isReturn()):
                break;
            item = self._items[item.endAddress()]
        # add jump tables for switch statements
        item = self._items.get(item.endAddress())
        while isinstance(item, DataItem):
            items.append(item)
            item = self._items[item.endAddress()]
        procStartAddress = items[0].startAddress()
        procEndAddress = items[-1].endAddress()
        for item in items:
            if isinstance(item, CodeBlock) and item.jumpTarget() is not None:
                if (item.jumpTarget() <= procStartAddress):
                    return
                if (item.jumpTarget() >= procEndAddress):
                    return
            addrsFrom = shortJumpsFrom.get(item.startAddress())
            if addrsFrom is not None:
                for addrFrom in addrsFrom:
                    if (addrFrom < procStartAddress):
                        return
                    if (addrFrom >= procEndAddress):
                        return
        for item in items:
            del self._items[item.startAddress()]
        self._items[addr] = Procedure(items, isUsed)

    def _isProcStartPattern(self, addr):
        return self.bytes(addr, addr + 3) == "558BEC"

    def makeProcedures(self):
        shortJumpsFrom = {}
        for addr in sorted(self._items.keys()):
            item = self._items[addr]
            if isinstance(item, CodeBlock) and item.jumpTarget() is not None:
                if item.isShortJump(self):
                    if not item.jumpTarget() in shortJumpsFrom:
                        shortJumpsFrom[item.jumpTarget()] = set()
                    shortJumpsFrom[item.jumpTarget()].add(addr)
        for addr in sorted(self._items.keys()):
            item = self._items.get(addr)
            if isinstance(item, CodeBlock):
                isUsed = item.hasLabel()
                if isUsed or self._isProcStartPattern(addr):
                    self._tryMakeProcedure(addr, shortJumpsFrom, isUsed)

    def commentsToString(self, addr):
        lines = []
        comments = self.comments(addr)
        if comments is not None:
            for comment in comments:
                lines.append(";{}".format(comment))
        return ''.join(lines)

    def toString(self, endDataAddress):
        writer = ImageWriter(self)
        for addr in sorted(self._items.keys()):
            if addr >= endDataAddress:
                break
            item = self._items[addr]
            writer.write(item)
        return writer.toString()

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

class SrcSymbols:
    def __init__(self):
        self.varNames = {}
        self.mangledNames = {}
        self.implementedProcedures = set()

    @staticmethod
    def ensure_symbols_for_module(symbols_dict, module):
        symbols = symbols_dict.get(module)
        if symbols is None:
            symbols = SrcSymbols()
            symbols_dict[module] = symbols
        return symbols

    @staticmethod
    def create_symbols_dict(varNames, mangledNames, implementedProcedures):
        symbols_dict = {}
        for (module, addr), var_name in varNames.items():
            symbols = SrcSymbols.ensure_symbols_for_module(symbols_dict, module)
            symbols.varNames[addr] = var_name
        for (module, addr), mangled_name in mangledNames.items():
            symbols = SrcSymbols.ensure_symbols_for_module(symbols_dict, module)
            symbols.mangledNames[addr] = mangled_name
        for module, addr in implementedProcedures:
            symbols = SrcSymbols.ensure_symbols_for_module(symbols_dict, module)
            symbols.implementedProcedures.add(addr)
        return symbols_dict

class AsmFiles:
    def __init__(self, dir):
        self._dir = dir

    @property
    def input_asm(self):
        return os.path.join(self._dir, "raw.txt")

    @property
    def input_data(self):
        return os.path.join(self._dir, "data.txt")

    @property
    def reloc(self):
        return os.path.join(self._dir, "reloc.txt")

    @property
    def module(self):
        return os.path.join(self._dir, "module.txt")

    @property
    def intermediate_asm(self):
        return os.path.join(self._dir, "code.str")

    @property
    def intermediate_export(self):
        return os.path.join(self._dir, "export_cmd.str")

    @property
    def intermediate_hash(self):
        return os.path.join(self._dir, "hash.str")

    @property
    def output_asm(self):
        return os.path.join(self._dir, "native.asm")

    @property
    def output_procedures(self):
        return os.path.join(self._dir, "procedures.inc")

    @property
    def output_variables(self):
        return os.path.join(self._dir, "variables.inc")

    @property
    def output_export(self):
        return os.path.join(self._dir, "export_cmd.txt")

    @property
    def uninitialised(self):
        return os.path.join(self._dir, "uninitialised.asm")

    @property
    def export_include(self):
        return os.path.join(self._dir, "export.inc")

    @property
    def import_include(self):
        return os.path.join(self._dir, "import.inc")

    @property
    def stdcall_defs(self):
        return os.path.join(self._dir, "stdcallDefs.cpp")

    @property
    def asm_main(self):
        return os.path.join(self._dir, "../asmMain.asm")

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
    length = len(bytes) // 2
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

def writeUninitialisedData(asm_files, imageMap, endDataAdddress):
    writer = ImageWriter(imageMap)
    for addr in sorted(imageMap.itemsMap().keys()):
        imageItem = imageMap.itemsMap()[addr]
        if imageItem.startAddress() >= endDataAdddress:
            writer.write(imageItem)
    f = openForWriting(asm_files.uninitialised)
    f.write(writer.toString())
    f.close()


def writeStdcallFunctions(asm_files, importReferences):
    f = openForWriting(asm_files.stdcall_defs)
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

def writeExportDeclarations(asm_files, imageMap):
    f = openForWriting(asm_files.export_include)
    for addr in sorted(imageMap.exports().keys()):
        f.write("public {}\n".format(imageMap.label(addr)))
    f.close()

def isCdeclMangling(exportName, internalName):
    return (internalName == '_' + exportName)

def writeExportSymbols(imageMap, exportFileName):
    f = open(exportFileName, "wt")
    exportAddrs = set(imageMap.exports().keys())
    for addr in sorted(exportAddrs):
        exportName = imageMap.exports()[addr]
        internalName = imageMap.label(addr)
        f.write("{} {} {}\n".format(toHex(addr), exportName, internalName))
    f.close()

def writeExportCmd(asm_files, symbols):
    with open(asm_files.intermediate_export) as f:
        lines = f.readlines()
    addr_export_regexp = re.compile(
        '(?P<addr>[\dABCDEF]+)\s(?P<exportName>\w+)\s(?P<internalName>\w+)'
    )
    exportAddrs = []
    exportNames = {}
    internalNames = {}
    for line in lines:
        match = re.search(addr_export_regexp, line)
        if match:
            addr = fromHex(match.group('addr'))
            exportName = match.group('exportName')
            internalName = match.group('internalName')
            if not addr in symbols.implementedProcedures:
                exportAddrs.append(addr)
                exportNames[addr] = exportName
                internalNames[addr] = internalName
    f = open(asm_files.output_export, "wt")
    for addr in exportAddrs:
        exportName = exportNames[addr]
        internalName = internalNames[addr]
        if addr in symbols.mangledNames:
            internalName = symbols.mangledNames[addr]
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
    module_regexp = re.compile('Module:\s+(?P<module>[\S]+)')
    addr_regexp = re.compile('Entry\s+point:\s+0x(?P<addr>[\dABCDEF]+)')
    mangling_regexp = re.compile('VC\+\+\s+mangling:\s+(?P<mangling>[\S]+)')
    proc_regexp = re.compile('\W(?P<proc>\w+)\s*\([^\(\)]*\)\s*\{')
    meta = False
    module = None
    addr_by_module = {}
    for line in lines:
        if line.find("/*") >= 0:
            meta = True
            module = None
            addr_by_module = {}
            mangling = None
        if line.find("*/") >= 0:
            meta = False
            definition = ""
            for module, addr in addr_by_module.items():
                mangledNames[(module, addr)] = mangling
        if line.find("BLD_NATIVE") >= 0:
            for module, addr in addr_by_module.items():
                nativeProcedures.add((module, addr))
        if meta:
            match = re.search(module_regexp, line)
            if match:
                module = match.group('module')
            match = re.search(addr_regexp, line)
            if match:
                addr_by_module[module] = fromHex(match.group('addr'))
            match = re.search(mangling_regexp, line)
            if match:
                mangling = match.group('mangling')
        elif (
            len(addr_by_module) > 0 and
            mangledNames[(module, addr_by_module[module])] is None
        ):
            definition += line
            if line.find("{") >= 0:
                cdecl_mangling = None
                match = re.search(proc_regexp, definition)
                if match:
                    proc_name = match.group('proc')
                    cdecl_mangling = "_{}".format(proc_name)
                for module, addr in addr_by_module.items():
                    fallback = "fn{}".format(toHex(addr))
                    mangledNames[(module, addr)] = cdecl_mangling or fallback
    f.close()
    return (mangledNames, set(mangledNames.keys()) - nativeProcedures)

def collectVariablesFromFile(fileName):
    varNames = {}
    f = open(fileName)
    lines = f.readlines()
    module_regexp = re.compile('Module:\s+(?P<module>[\S]+)')
    addr_regexp = re.compile('Data\s+address:\s+0x(?P<addr>[\dABCDEF]+)')
    name_regexp = re.compile('(\W+(?P<name>\w+)(\s*\[\s*\d*\s*\])*\s*)?(=\s*\d*\s*)?;')
    module = None
    addr_by_module = {}
    for line in lines:
        match = re.search(module_regexp, line)
        if match:
            module = match.group('module')
        match = re.search(addr_regexp, line)
        if match:
            addr_by_module[module] = fromHex(match.group('addr'))
        if len(addr_by_module) > 0:
            match = re.search(name_regexp, line)
            if match:
                for module, addr in addr_by_module.items():
                    varNames[(module, addr)] = match.group('name')
                addr_by_module = {}
    f.close()
    return varNames

def collectSymbolsFromSources(src_dir):
    varNames = {}
    mangledNames = {}
    implementedProcedures = []
    for (root, dirs, files) in os.walk(src_dir):
        for file in files:
            if file.lower().endswith(".cpp") or file.lower().endswith(".h"):
                fileName = os.path.join(root, file)
                (names, implemented) = collectProceduresFromFile(fileName)
                mangledNames.update(names)
                implementedProcedures += implemented
                varNames.update(collectVariablesFromFile(fileName))
    return SrcSymbols.create_symbols_dict(
        varNames,
        mangledNames,
        set(implementedProcedures)
    )

def openForWriting(filename):
    if filename.endswith(".cpp"):
        lineStart = "//"
    else:
        lineStart = ";"
    autoGenMsg = \
'''{start} This file was automatically generated by {file}
{start} and should not be edited.
'''.format(
        start=lineStart,
        file=os.path.basename(__file__)
    )
    f = open(filename, "wt")
    f.write(autoGenMsg)
    return f

def createAsmCode(asm_files):
    f = open(asm_files.input_asm)
    lines = f.readlines()
    f.close()
    reloc = readRelocations(asm_files.reloc)
    userData = readDataItems(asm_files.input_data)
    addr_label_regexp = re.compile('^(?P<addr>[\dABCDEF]+):\s+(?P<bytes>[\dABCDEF]+)\s+(?P<instr>\S.*)?$')
    print("Fill data structures...")
    entryPoint = None
    export = None
    mem = MemoryArea(reloc)
    imageMap = ImageMap(mem)
    comments = []
    for line in lines:
        match = re.search(addr_label_regexp, line)
        if not match:
            comments.append(line)
            entryPoint = entryPoint or extractEntryPoint(line)
            export = export or extractExport(line)
        else:
            addr = fromHex(match.group('addr'))
            instr = match.group('instr')
            bytes = match.group('bytes')
            length = len(bytes) // 2
            mem.addBytes(addr, bytes)
            endDataAddress = addr + length
            if instr is not None:
                item = AsmInstruction(addr, instr.rstrip(), length)
            else:
                item = DataItem(addr, addr + length)
            imageMap.add(addr, item)
            if export is not None:
                imageMap.addExport(addr, export)
                export = None
            imageMap.addComments(addr, comments)
            comments = []
    imageMap.resolveAddress(entryPoint, '__startup')
    print("Removing overlapped items...")
    imageMap.removeOverlappedItems()
    print("Merging user data...")
    imageMap.mergeUserData(userData)
    print("Removing invalid instructions...")
    imageMap.removeInvalidInstructions()
    print("Make blocks...")
    imageMap.makeBlocks()
    print("Merge adjacent data iiems...")
    imageMap.mergeAdjacentDataItems()
    print("Processing data...")
    for imageItem in set(imageMap.itemsMap().values()):
        if isinstance(imageItem, CodeBlock):
            imageItem.processData(imageMap)
    print("Splitting data items...")
    imageMap.splitDataItems()
    for imageItem in set(imageMap.itemsMap().values()):
        if isinstance(imageItem, DataItem):
            imageItem.applyRelocs(imageMap)
    print("Make procedures...")
    imageMap.makeProcedures()
    print("Adjust instructions...")
    for imageItem in set(imageMap.itemsMap().values()):
        if isinstance(imageItem, CodeItem):
            imageItem.adjustInstructions(imageMap)
    print("Writing data...")
    f = openForWriting(asm_files.intermediate_asm)
    f.write(imageMap.toString(endDataAddress))
    f.write("; Unresolved addresses:\n")
    for addr in sorted(imageMap.unresolvedAddresses()):
        f.write("l{} dd 012345678h\n".format(toHex(addr)))
    f.close()
    writeUninitialisedData(asm_files, imageMap, endDataAddress)
    f = openForWriting(asm_files.import_include)
    for impref in imageMap.importReferences():
        f.write("externdef {}: ptr\n".format(impref.label()))
    f.close()
    writeExportDeclarations(asm_files, imageMap)
    writeExportSymbols(imageMap, asm_files.intermediate_export)
    writeStdcallFunctions(asm_files, imageMap.importReferences())

def ensureAsmCode(asm_files):
    if (
        not os.path.exists(asm_files.intermediate_asm) or
        not os.path.exists(asm_files.intermediate_export)
    ):
       createAsmCode(asm_files)

def readAsmCode(codeFileName):
    with open(codeFileName) as f:
        return f.readlines()

def calc_hash(symbols):
    hasher = hashlib.sha256()
    json_str = json.dumps(
        (
            symbols.varNames,
            symbols.mangledNames,
            sorted(symbols.implementedProcedures)
        ),
        sort_keys=True
    )
    hasher.update(json_str.encode())
    return hasher.digest()

def is_hash_changed(hashFileName, new_hash):
    try:
        with open(hashFileName, "rb") as f:
            existing_hash = f.read()
            return existing_hash != new_hash
    except Exception:
        return True

def write_hash(hashFileName, new_hash):
    with open(hashFileName, "wb") as f:
        f.write(new_hash)

def read_module_name(asm_files):
    with open(asm_files.module, "rt") as f:
        return f.readlines()[0]

def run():
    src_dir = os.path.abspath('src')
    print("Collect symbols from sources...")
    symbols_dict = collectSymbolsFromSources(src_dir)
    for (root, dirs, files) in os.walk(src_dir):
        if "raw.txt" in files:
            asm_files = AsmFiles(root)
            module_name = read_module_name(asm_files)
            print("Processing {}".format(module_name))
            process_asm_dir(asm_files, symbols_dict[module_name])

def process_asm_dir(asm_files, symbols):
    symbols_hash = calc_hash(symbols)
    print("Checking hash for collected symbols...")
    if not is_hash_changed(asm_files.intermediate_hash, symbols_hash):
        print("Nothing to do...")
        return
    ensureAsmCode(asm_files)
    print("Reading code...")
    lines = readAsmCode(asm_files.intermediate_asm)
    print("Writing code...")
    f = open(asm_files.output_asm, "wt")
    isImplemented = False
    for line in lines:
        if line.startswith("l"):
            if line.find("PROC") >= 0:
                addr = fromHex(line[1:9])
                isImplemented = addr in symbols.implementedProcedures
                if isImplemented:
                    f.write(
                        "{} call l{}; Implemented in c++ code\n".format(
                            ' ' * 10,
                            toHex(addr)))
        if not isImplemented:
            f.write(line)
        elif line.find("ENDP") >= 0:
            isImplemented = False
    f.close()
    print("Writing export symbols command line...")
    writeExportCmd(asm_files, symbols)
    print("Writing procedures declarations...")
    f = openForWriting(asm_files.output_procedures)
    for addr in sorted(symbols.mangledNames.keys()):
        name = symbols.mangledNames[addr]
        label = "l{}".format(toHex(addr))
        f.write("externdef {}: near\n{} equ {}\n".format(name, label, name))
    f.close()
    print("Writing variable declarations...")
    f = openForWriting(asm_files.output_variables)
    for addr in sorted(symbols.varNames.keys()):
        name = symbols.varNames[addr]
        label = "g{}".format(toHex(addr))
        f.write("public _{}\n{} equ _{}\n".format(name, label, name))
    f.close()
    # Touch asm file to force recompile
    pathlib.Path(asm_files.asm_main).touch()
    print("Writing hash for collected symbols...")
    write_hash(asm_files.intermediate_hash, symbols_hash)

if __name__ == '__main__':
    start_time = time.time()
    run()
    print("Converted in %.2f seconds" % (time.time() - start_time))
