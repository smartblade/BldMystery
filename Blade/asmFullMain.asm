.586
.model flat
option M510
option casemap:none
assume fs: nothing

image segment write execute PUBLIC
include export.inc
include import.inc
include full.asm
image ends

END __startup
