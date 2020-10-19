#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	unsigned char rbuff[64];
	int fd; 
	fd = open("desd",0_RDONLY);
	read(fd,rbuff,64);
	printf("Received from sender: %s\n", rbuff);
	close(fd);
	return 0;
}