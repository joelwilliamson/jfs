#include "fetch_data.h"


int read_sector(struct CHS_address address, void* buffer) {
	__asm__(".code16\n"
		"movb $0x02, %ah\n"
		"
