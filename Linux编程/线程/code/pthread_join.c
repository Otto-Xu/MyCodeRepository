#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid;

void *func(void *arg)
{
	if(tid == pthread_self())
		printf("hi, i am a thread1\n");

	#if 0
	//返回指针
	char *p = "hello";
	printf("p: %p\n", p);
	pthread_exit((void *)p);
	#endif

	#if 0
	//返回数组
	char p[] = "hello";
	printf("p: %p\n", p);
	pthread_exit((void *)p);
	#endif	

	#if 0
	//返回值
	pthread_exit((void *)10);
	#endif

	#if 1
	//返回变量
	int a = 10;
	printf("&a: %p\n", &a);
	pthread_exit((void *)&a);
	#endif
}

int main(int argc, char *argv[])
{
	int ret;
	ret = pthread_create(&tid, NULL, func, NULL);
	if(ret != 0)
	{
		perror("pthread_create error");
		return 0;
	}
	
	#if 0
	//接收指针
	char *ptr;
	pthread_join(tid, (void *)&ptr);
	printf("ptr: %p\n", ptr);
	printf("ptr: %s\n", ptr);
	#endif
	
	#if 0
	//接收数组
	char *ptr;
	pthread_join(tid, (void *)&ptr);
	printf("ptr: %p\n", ptr);
	printf("ptr: %s\n", ptr);
	#endif

	#if 0
	//接收值
	int ptr;
	pthread_join(tid, (void *)&ptr);
	printf("ptr: %p\n", &ptr);
	printf("ptr: %d\n", ptr);
	#endif

	#if 1
	//接收变量
	int **ptr;
	pthread_join(tid, (void **)ptr);
	printf("*ptr: %p\n", *ptr);
	//printf("*ptr: %d\n", *ptr);
	#endif

	return 0;
}
