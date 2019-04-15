
import re

num_regexp = re.compile('(?P<number>[\dABCDEF]+)')
cmds = 'call|jmp|je|jne|jb|jnb|jbe|jl|jnl|jle|jg|ja|js|jns|jp|jnp|jo|jno|loop|loopnz'
direct_transfer_regexp = re.compile('^(?P<cmd>{})\s+(?P<target>0x[\dABCDEF]+)\W*$'.format(cmds))
external_ref_regexp = re.compile('(?P<extern>\w+\.\S+)')

def toHex(n):
    return format(n, '08X')

def fromHex(h):
    return int(h, 16)

def resolveAddress(addr, instrMap, unresolvedAddresses):
    if addr in instrMap:
        instrMap[addr].showLabel()
    else:
        unresolvedAddresses.append(addr)

class CommentLine:
    _line = None
    def __init__(self, line):
        self._line = line

    def toString(self):
        return ";{}".format(self._line)


class AsmInstruction:
    _addr = None
    _instr = None
    _bytes = None
    _length = 0
    _showLabel = False
    def __init__(self, addr, instr, bytes):
        self._addr = addr
        self._instr = instr
        self._bytes = bytes
        self._length = len(bytes) / 2

    def showLabel(self):
        self._showLabel = True

    def addHexPrefix(self):
        self._instr = num_regexp.sub('0x\g<number>', self._instr)

    def applyRelocs(self, reloc, instrMap, unresolvedAddresses):
        for a in range(self._addr, self._addr + self._length):
            if a in reloc:
                targetAddr = fromHex(reloc[a])
                label = "l{}".format(toHex(targetAddr))
                (self._instr, count) = re.subn(reloc[a], label, self._instr, 1)
                if count == 0:
                    self._instr += "; Failed to apply reloc"
                else:
                    resolveAddress(targetAddr, instrMap, unresolvedAddresses)

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
        return "{} {}\n".format(label, self._instr)

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

if __name__ == '__main__':
    f = open("Blade_patched.txt")
    lines = f.readlines()
    f.close()
    reloc = readRelocations("reloc.txt")
    addr_label_regexp = re.compile('^(?P<addr>[\dABCDEF]+):\s+(?P<bytes>[\dABCDEF]+)\s+(?P<instr>\S.*)$')
    print("Fill data structures...")
    lineItems = []
    instrMap = {}
    for line in lines:
        match = re.search(addr_label_regexp, line)
        if not match:
            lineItems.append(CommentLine(line))
        else:
            addr = fromHex(match.group('addr'))
            instr = match.group('instr').rstrip()
            bytes = match.group('bytes')
            asmInstruction = AsmInstruction(addr = addr, instr = instr, bytes = bytes)
            instrMap[addr] = asmInstruction
            lineItems.append(asmInstruction)
    print("Processing data...")
    unresolvedAddresses = []
    for lineItem in lineItems:
        if isinstance(lineItem, AsmInstruction):
            lineItem.resolveExternalCalls()
            lineItem.addHexPrefix()
            lineItem.applyRelocs(reloc, instrMap, unresolvedAddresses)
            lineItem.resolveDirectTransferAddress(instrMap, unresolvedAddresses)
    print("Writing data...")
    f = open("Blade_patched_converted.txt", "wt")
    for lineItem in lineItems:
        f.write(lineItem.toString())
    for addr in sorted(unresolvedAddresses):
        f.write(";{}\n".format(toHex(addr)))
    f.close()
