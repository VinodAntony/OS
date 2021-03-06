#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t count_sem;
int count = 0;

void* inc_thread(void *arg){
	while(1){
		sem_wait(&count_sem);
		++count;
		printf("Increment thread: %d\n",count);
		sem_post(&count_sem);
	}
}
void* dec_thread(void *arg){
	while(1){
		sem_wait(&count_sem);
		--count;
		printf("Decrement thread: %d\n",count);
		sem_post(&count _sem);
	}
}
int main(int argc, char const *argv[])
{
	pthread_t tid_inc, tid_dec; 
	sem_init(&count_sem, 0, 1);
	pthread_create(&tid_inc, NULL, inc_thread, NULL);
	pthread_create(&tid_dec, NULL, dec_thread, NULL);
	/*printf("after thread creation\n");
	sleep(1);
	printf("after sleep function\n");*/
	pthread_join(tid_inc,NULL);
	pthread_join(tid_dec,NULL);
	sem_destroy(&count_sem); 
	return 0;
}

