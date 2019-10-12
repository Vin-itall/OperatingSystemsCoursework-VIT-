#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

pthread_t Philosophers[5];
sem_t Chopsticks[5];
void* Eat(int n)
{
	sem_wait(&Chopsticks[n]);
	sem_wait(&Chopsticks[(n+1)%4]);
	printf("\n Philosopher %d is eating",n);
	sleep(3);
	sem_post(&Chopsticks[n]);
	sem_post(&Chopsticks[(n+1)%4]);
	printf("\n Philosopher %d finished eating",n);
}
int main()
{
	for(int i=0;i<5;i++)
	{	
		sem_init(&Chopsticks[i],0,1);
	}
	for(int i=0;i<5;i++)
	{
		pthread_create(&Philosophers[i],NULL,Eat,(int *)i);
	}
	for(int i=0;i<5;i++)
	{
		pthread_join(Philosophers[i],NULL);
	}
return 0;
}
