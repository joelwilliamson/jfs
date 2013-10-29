#include "fetch_data.h"

#include <string.h>


extern void* img;

const uint16_t bytes_per_sector = 512;
const uint8_t num_head = 255; // Heads per cylinder
const uint8_t num_sectors = 63; // Sectors per head (i.e. track)

int read_sector(struct CHS_address address, void* buffer, uint8_t num_sectors) {
	uint32_t bytes_to_read = num_sectors*bytes_per_sector;

	uint32_t offset = (address.cylinder * num_head + address.head) * num_sectors + (address.sector - 1);
	// See http://en.wikipedia.org/wiki/Cylinder-head-sector
	
	memcpy(buffer,img+offset,bytes_to_read);
	return 0;
}
