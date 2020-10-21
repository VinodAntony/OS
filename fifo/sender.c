#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	int fd; 
	open("desd",0_WRONLY);
	write(fd, "cdac\n", 5);
	close(fd);
	return 0;
}