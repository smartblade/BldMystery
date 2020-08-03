.586
.model flat
option M510
option casemap:none
assume fs: nothing

image segment write execute PUBLIC
include procedures.inc
include variables.inc
include export.inc
include import.inc
include native.asm
image ends
.data?
include uninitialised.asm

END __startup
