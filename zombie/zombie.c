#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t id; 
	id = fork();

	if(id == 0){
		//child
		printf("Child starting\n");
		sleep(2);
		printf("child exiting\n");
	}
	else{
		//parent
		printf("parent starting\n");
		sleep(12);
		printf("parent exiting\n");
	}
	return 0;
}