#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int count = 0;

void* inc_thread(void *arg){
	while(1){
		++count;
		printf("Increment thread: %d\n",count);
	}
}
void* dec_thread(void *arg){
	while(1){
		--count;
		printf("Decrement thread: %d\n",count);
	}
}
int main(int argc, char const *argv[])
{
	pthread_t tid_inc, tid_dec; 
	
	pthread_create(&tid_inc, NULL, inc_thread, NULL);
	pthread_create(&tid_dec, NULL, dec_thread, NULL);
	/*printf("after thread creation\n");
	sleep(1);
	printf("after sleep function\n");*/
	pthread_join(tid_inc,NULL);
	pthread_join(tid_dec,NULL); 
	return 0;
}
