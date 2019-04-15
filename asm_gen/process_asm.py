
import re

class AsmInstruction:
    _addr = None
    _instr = None
    _length = 0
    def __init__(addr, instr, length):
        self._addr = addr
        self._instr = instr
        seld._length = length    

def readRelocations(relocFileName):
    addr_value_regexp = re.compile('^;;\s(?P<addr>0x[\dABCDEF]+)\s(?P<value>0x[\dABCDEF]+)')
    reloc = dict()
    f = open(relocFileName)
    for line in f.readlines():
        line = line.rstrip()
        addr = addr_value_regexp.sub('\g<addr>', line)
        value = addr_value_regexp.sub('\g<value>', line)
        reloc[int(addr, 0)] = value
    f.close()
    return reloc

def applyRelocs(addr, length, instr, reloc):
    for a in range(addr, addr + length):
        if a in reloc:
            label = "l{}".format(format(int(reloc[a], 0), '08X'))
            (instr, count) = re.subn(reloc[a], label, instr, 1)
            if count == 0:
                instr += ";Failed to apply reloc"
    return instr

if __name__ == '__main__':
    f = open("Blade_patched.txt")
    lines = f.readlines()
    f.close()
    reloc = readRelocations("reloc.txt")
    f = open("Blade_patched_converted.txt", "wt")
    addr_label_regexp = re.compile('^(?P<addr>[\dABCDEF]+):\s+(?P<bytes>[\dABCDEF]+)\s+(?P<instr>\S.*)$')
    num_regexp = re.compile('(?P<number>[\dABCDEF]+)')
    for line in lines:
        match = re.search(addr_label_regexp, line)
        if not match:
            line = ';' + line
        else:
            line = line.rstrip()
            addr = int(addr_label_regexp.sub('\g<addr>', line), 16)
            instr = addr_label_regexp.sub('\g<instr>', line)
            bytes = addr_label_regexp.sub('\g<bytes>', line)
            instr = num_regexp.sub('0x\g<number>', instr)
            length = len(bytes) / 2
            instr = applyRelocs(addr, length, instr, reloc)
            line = "l{}: {}\n".format(format(addr, '08X'), instr)
        f.write(line)
    f.close()
