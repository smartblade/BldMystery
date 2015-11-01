
#include "bladex_int.h"

static int unknown1(void);
static void unknown2(void);

/*
* Module:                 Bladex.dll
* Entry point:            0x10019060
*/

int unknown1() {
        return 1;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1001906A
*/

void unknown2() {
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1001906F
*/

void perform_heap_check() {
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10019074
*/

int heap_check_set_mark() {
        return 0;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10019086
*/

void heap_check_all_allocations(int i) {
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001908B
*/

void heap_check_delay_free(int i) {
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10019090
*/

void heap_check_system_memory(int i) {
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10019095
*/

void heap_check_leaks(int i) {
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1001909A
*/

int dump_memory_leaks(const char *s) {
        return 0;
}

