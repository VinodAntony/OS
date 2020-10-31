#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a, b; 
int sum; 
sem_t inp2proc, proc2inp;
void* input_thread(void* data){
	
	while(1){

		printf("T1: Received signal from processing thread\n");
		sem_wait(&proc2inp);
		printf("T1: Getting new inputs\n");
		scanf("%d %d",&a,&b);
		printf("T1: Got new inputs\n");
		sem_post(&inp2proc);
		printf("T1: Sending signal to processing thread\n");
	}
}

void* processing_thread(void* data){
	while(1){

		printf("T2: Waiting for signal from Input thread\n");
		sem_wait(&inp2proc);
		printf("T2: Starting Processing\n");
		sum = a+b; 
		printf("T2: Sum : %d\n",sum );
		sem_post(&proc2inp);
		printf("T2: Sending Signal to Input thread \n");
	}
}



int main(int argc, char const *argv[])
{
	pthread_t input_id, processing_id;
	sem_init(&inp2proc, 0, 0);
	sem_init(&proc2inp, 0, 1);
	pthread_create(&input_id, NULL, input_thread, NULL);
	pthread_create(&processing_id, NULL, processing_thread, NULL);
	
	pthread_join(input_id,NULL);
	pthread_join(processing_id,NULL);


	return 0;
}