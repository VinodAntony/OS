/*get 2 int inputs :P1
 send it to p2 :p1
 recv two integers : p2
 add two integers :p2
 send result to p1 :p2
 print result :p1
 */
/*receives 2 inputs from P1 , calculates the sum and sends the sum back */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int rbuff[3];
	int fd1; 
	mkfifo("p1 to p2",S_IRUSR | S_IWUSR);
	fd1 = open("p1 to p2",O_RDONLY);
	read(fd1 ,rbuff, 8);
	printf("\n\tP2\n\nReceived from P1: %d and %d for addition \nSum has been sent to P1\n", rbuff[0], rbuff[1]);
	rbuff[2] = rbuff[0]+rbuff[1];
	close(fd1);
	
	mkfifo("p2 to p1",S_IRUSR | S_IWUSR);
	fd1 = open("p2 to p1",O_WRONLY);
	write(fd1,&rbuff[2],4);
	close(fd1);
	return 0;
}