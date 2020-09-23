#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define PATH "/tmp"

int main(int argc, char *argv[])
{
	sem_t *sem;
	//创建一个posix的有名信号量
	sem = sem_open(PATH, O_CREAT, 0644, 1);
	if(SEM_FAILED == sem)
	{
		perror("sem_open error");
		return 0;
	}

	//P操作
	sem_wait(sem);

	//临界区代码

	//V操作
	sem_post(sem);

	sem_close(sem);
	return 0;
}
