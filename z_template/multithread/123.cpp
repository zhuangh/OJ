#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>  /* Semaphore */

#define THREADS 4 
sem_t mutex1;
sem_t mutex2;
sem_t mutex3;
sem_t mutex4;

void * monitor_thread1 (void* data)
{
	int t=1;
	for (int i=0;i<10;i++){
	    sem_wait(&mutex1);       /* down semaphore */
	    printf("%d \n",t);
	    sem_post(&mutex2);       /* down semaphore */
	}
}
	
void * monitor_thread2 (void* data)
{
	int j=2;
	for (int i=0;i<10;i++){
	    sem_wait(&mutex2);       /* down semaphore */
	    printf("%d \n",j);
	    sem_post(&mutex3);       /* down semaphore */
	}
}

void * monitor_thread3 (void* data)
{

	int t=3;
	for (int i=0;i<10;i++){
	    sem_wait(&mutex3);       /* down semaphore */
	    printf("%d \n",t);
	    sem_post(&mutex4);       /* down semaphore */
	}
}

void * monitor_thread4 (void* data)
{
	int t=4;
	for (int i=0;i<10;i++){
	    sem_wait(&mutex4);       /* down semaphore */
	    printf("%d \n",t);
	    sem_post(&mutex1);       /* down semaphore */
	}
}

int main(int argc, char **argv)
{
	pthread_t tid[THREADS];
	
	sem_init(&mutex1, 0, 1);
	sem_init(&mutex2, 0, 0);
	sem_init(&mutex3, 0, 0);
	sem_init(&mutex4, 0, 0);

	pthread_create(&tid[2], NULL, monitor_thread3, NULL);
	pthread_create(&tid[0], NULL, monitor_thread1, NULL);
	pthread_create(&tid[1], NULL, monitor_thread2, NULL);
	pthread_create(&tid[3], NULL, monitor_thread4, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);

	sem_destroy(&mutex1);
	sem_destroy(&mutex2);
	sem_destroy(&mutex3);
	sem_destroy(&mutex4); 

	return 0;
}



