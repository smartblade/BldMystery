
#include "bladex_int.h"

static int unknown1(void);
static void unknown2(void);

// address: 0x10019060
int unknown1() {
        return 1;
}

// address: 0x1001906a
void unknown2() {
}

// address: 0x1001906f
void perform_heap_check() {
}


// address: 0x10019074
int heap_check_set_mark() {
        return 0;
}


// address: 0x10019086
void heap_check_all_allocations(int i) {
}


// address: 0x1001908b
void heap_check_delay_free(int i) {
}


// address: 0x10019090
void heap_check_system_memory(int i) {
}


// address: 0x10019095
void heap_check_leaks(int i) {
}


// address: 0x1001909a
int dump_memory_leaks(const char *s) {
        return 0;
}

