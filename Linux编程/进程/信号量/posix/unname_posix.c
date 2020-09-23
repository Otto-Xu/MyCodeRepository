#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define PATH "/tmp"

int main(int argc, char *argv[])
{
	sem_t *sem;

	//初始化
	sem_init(sem, 0, 1);

	//P操作
	sem_wait(sem);

	//临界区代码

	//V操作
	sem_post(sem);

	sem_destroy(sem);

	return 0;
}
