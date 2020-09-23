#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid;
pthread_t tid2;


void *func(void *arg)
{
	if(tid == pthread_self())
	{
		int *my_arg1;
		my_arg1 = (int *)arg;
		printf("hi, i am a thread1: %d\n", *my_arg1);
	}
	else if(tid2 == pthread_self())
	{
		int *my_arg2;
		my_arg2 = (int *)arg;
		printf("hi, i am a thread2: %d\n", *my_arg2);
	}

	while(1);
}

int main(int argc, char *argv[])
{
	int ret;
	int data1 = 111;
	int data2 = 222;

	ret = pthread_create(&tid, NULL, func, (void *)&data2);
	if(ret != 0)
	{
		perror("pthread_create error");
		return 0;
	}

	ret = pthread_create(&tid2, NULL, func, (void *)&data2);
	if(ret != 0)
	{
		perror("pthread_create error");
		return 0;
	}

	while(1);

	return 0;
}
