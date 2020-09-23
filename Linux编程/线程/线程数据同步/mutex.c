#include <stdio.h>
#include <pthread.h>

pthread_t tid;
pthread_t tid2;

long long g_cnt;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void *arg)
{
	long long i = 0;

	for(i = 0; i < 50000000; i++)
	{
		pthread_mutex_lock(&mutex);
		g_cnt++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char *argv[])
{
	int ret;

	g_cnt = 0;

	ret = pthread_create(&tid, NULL, func, NULL);
	if(ret != 0)
	{
		perror("pthread_create error");
		return 0;
	}

	ret = pthread_create(&tid2, NULL, func, NULL);
	if(ret != 0)
	{
		perror("pthread_create error");
		return 0;
	}

	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("%lld\n", g_cnt);

	pthread_mutex_destroy(&mutex);
	
	return 0;
}
