#include <stdint.h>

struct CHS_address {
	uint8_t sector; // There are max 63 sectors per head
	uint8_t head; // max 255 heads per cylinder
	uint16_t cylinder; // max 1024 cylinders
};

struct LBA_address {
	uint32_t address; // This allows a nice union with CHS
};
	

struct inode {
	uint32_t size;
	union {
		struct CHS_address chs;
		struct LBA_address lba;
	};
};

struct dirent {
	char name [256];
	uint8_t mode; // Permission bytes, etc.
	struct inode * node;
};

struct directory {
	uint64_t numEntries;
	struct dirent * entries;
};
