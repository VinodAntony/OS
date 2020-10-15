#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){
	pid_t id;
	pid_t parent_id; 
	id = getpid();
	parent_id = getppid();

	printf("PID: %d\n",id );
	printf("PPID: %d\n",parent_id );

	return 0;	
}
