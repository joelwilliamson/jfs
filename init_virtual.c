#include "init_virtual.h"

#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h> // For struct stat

void * img;

int init_virtual(char * filename) {
	int source = open(filename,O_RDONLY);

	if (source == -1) error(1,errno,"The source file failed to open");

	struct stat buffer;
	stat(filename,&buffer);
	unsigned int size = buffer.st_size;

	img = malloc(size);

	if (read(source,img,size) == -1) error(1,errno,"Read failed");

	return 0;
}
