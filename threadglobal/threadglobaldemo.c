#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int count = 0 ; 

void* thread(void *arg){

	++count; 
	printf("thread created\n");
}

int main(int argc, char const *argv[])
{
	++count; 
	pthread_t tid; 
	printf("Before thread creation\n");
	pthread_create(&tid, NULL, thread, NULL);
	printf("after thread creation\n");
	sleep(1);
	printf("after sleep function\n");
	return 0;
}

