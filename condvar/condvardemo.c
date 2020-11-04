#include <stdio.h>
#include <pthread.h>

int flag = 0;
pthread_mutex_t m1 = _PTHREAD_MUTEX_INITIALIZER; 

void* thread_1(void* data){

	while(flag!=1){
		;

	}

}
void* thread_2(void* data){

	flag = 1; 
	
}

int main(int argc, char const *argv[])
{
	pthread_t t1, t2; 
	pthread_create(&t1, NULL, thread_1, NULL);
	pthread_create(&t1, NULL, thread_1, NULL);
	return 0;
}