#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
sem_t mutex,Full,Empty;
int Array[5];
 
void* Produce(void* arg)
{
    //wait
	sem_wait(&Empty);
    sem_wait(&mutex);
    printf("\nProducing..\n");
    //critical section
	for(int i=0;i<5;i++)
	{
		if(Array[i]==0)
		{
			printf("Please Enter Product: ");
			scanf("%d",&Array[i]); //Here it is produced
		}
	} 
	for(int i=0;i<5;i++)
	{
		printf(":%d",Array[i]);
	}    
    //signal
    printf("\nProduced...\n");
    sem_post(&mutex);
	sem_post(&Full);
}
void* Consume(void* arg)
{
    //wait
	sem_wait(&Full);
    sem_wait(&mutex);
    printf("\nConsuming..\n");
    //critical section
	int Consumed;
	printf("Enter No. Of Products To Be Consumed: ");
	scanf("%d",&Consumed);
	for(int i=0;i<Consumed;i++)
	{
		if(Array[i]!=0)
		{
			Array[i]=0;
		}
	}
	for(int i=0;i<5;i++)
	{
		printf(":%d",Array[i]);
	}     
    //signal
    printf("\nConsumed..\n");
    sem_post(&mutex);
	sem_post(&Empty);
} 
 
int main()
{
    sem_init(&mutex, 0, 1);
	sem_init(&Full, 0, 0);
	sem_init(&Empty, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,Consume,NULL);
    sleep(2);
    pthread_create(&t2,NULL,Produce,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}
