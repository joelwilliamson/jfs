#include "types.h"

/* read_sector will copy the bytes in the given sectors into the buffer, a
 * section of memory allocated by the caller. It will copy numSectors sectors,
 * provided they all fall on the same cylinder/head
 * 
 * Return value: 0 on success
 * 		non-zero on failure
 */
int read_sector(struct CHS_address address, void* buffer, uint8_t num_sectors);
