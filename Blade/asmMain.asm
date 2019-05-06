.586
.model flat
option M510
option casemap:none
assume fs: nothing

image segment write execute PUBLIC
include Blade_patched_export.inc
include Blade_patched_import.inc
include Blade_patched_converted.txt
image ends

END __startup
