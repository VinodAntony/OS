#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	pid_t id; 
	
	printf("Before the fork\n");
	id = fork();
	//printf("After the fork id %d\t PID %d\t PPID\t %d \n",id,getpid(),getppid());

	if(id == 0){
		printf("IN child: pid = %d\t PPID = %d\n",getpid(),getppid());
	}
	else{
		printf("In parentpid = %d\t PPID = %d\n",getpid(),getppid());
	}
	return 0;
}