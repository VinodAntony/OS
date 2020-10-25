/*get 2 int inputs :P1
 send it to p2 :p1
 recv two integers : p2
 add two integers :p2
 send result to p1 :p2
 print result :p1
 */
/*gets 2 inputs from user and sends it to P2, then receives sum from P2 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int* adder(void){
	
	printf("\n\tP1\n\n");
	printf("Enter 2 numbers for addition\n");
	int* arr = (int*)malloc(sizeof(int)*2);
	scanf("%d %d",&arr[0],&arr[1]);
	printf("%d and %d have been sent to P2\nWaiting for sum from P2\n",arr[0],arr[1]);
	return arr; 
}


int main(int argc, char const *argv[])
{
	int fd; 
	int* send = adder();
	int sum[1];
	mkfifo("p1 to p2",S_IRUSR | S_IWUSR);
	fd = open("p1 to p2",O_WRONLY);
	write(fd,send,8);
	close(fd);

	mkfifo("p2 to p1",S_IRUSR | S_IWUSR);
	fd = open("p2 to p1",O_RDONLY);
	read(fd,sum,4);
	printf("Received sum from P2 : %d\n",sum[0]);
	close(fd);

	return 0;
}