#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h> //printf

int main(void) {
	struct stat bufo;

	stat("/bin/echo", &bufo);
	printf("Device ID: %ld\n", bufo.st_dev);
	printf("Inode number: %ld\n", bufo.st_ino);
	printf("Mode: %o\n", bufo.st_mode);
	printf("Number hard links: %ld\n", bufo.st_nlink);
	printf("User ID: %d\n", bufo.st_uid);
	printf("Group ID: %d\n", bufo.st_gid);
	printf("Device ID(special file): %ld\n", bufo.st_rdev);
	printf("Size in bytes: %ld\n", bufo.st_size);
	printf("Block size for filesystem: %ld\n", bufo.st_blksize);
	printf("Blocks allocated: %ld\n", bufo.st_blocks);

	/*
	**lstat() is identical to stat(), except that if pathname is  a  symbolic
    **link,  then  it returns information about the link itself, not the file
    **that it refers to.
	**
	**fstat() is identical to stat(), except that the file about which infor‐
    **mation is to be retrieved is specified by the file descriptor fd.
	**
	**int fstat(int fd, struct stat *statbuf);
	*/
}
