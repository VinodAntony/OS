#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	unsigned char rbuff[128];
	pid_t id; 
	int pfd[2];
	pipe(pfd);

	id = fork();
	//statements below this will be done for parent and child 
	if(id == 0){
		read(pfd[0], rbuff, 128);
		printf("child : %s\n",rbuff );
		close(pfd[0]);
		//child process
	}
	else{
		write(pfd[1],"cdac\n",5);
		close(pfd[1]);
		//parent process
	}
	return 0;
}