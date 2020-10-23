#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int count = 0 ; 
int main(int argc, char const *argv[])
{
	pid_t id; 
	
	printf("Before the fork\n");
	id = fork();
	//printf("After the fork id %d\t PID %d\t PPID\t %d \n",id,getpid(),getppid());

	if(id == 0){ // child 
		sleep(1); 
		printf("IN child: pid = %d\t PPID = %d\n",getpid(),getppid());
		printf("count child = %d",count);
	}
	else{
		count++;
		printf("In parentpid = %d\t PPID = %d\n",getpid(),getppid());
		printf("count in parent = %d\n",count );
	}
	return 0;
}