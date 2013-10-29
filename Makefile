CFLAGS=-Wall -Werror

fetch_data_virtual.o: fetch_data.h fetch_data_virtual.c
	gcc ${CFLAGS} -S -o fetch_data_virtual.o fetch_data_virtual.c

init_virtual.o: init_virtual.h init_virtual.c
	gcc ${CFLAGS} -S -o init_virtual.o init_virtual.c



all: init_virtual.o fetch_data_virtual.o
