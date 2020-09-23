#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "shmdata.h"

int main()
{
	int running = 1;

	//建立IPC通讯
	key_t key;
	key = ftok(PATH, PROJ_ID);
	if(-1 == key)
	{
		perror("ftok error");
		return 0;
	}
	
	//创建共享内存
	int shmid;
	shmid = shmget(key, 1024, IPC_CREAT|0644);
	if(-1 == shmid)
	{
		perror("shmget error");
		return 0;
	}

	//将共享内存连接到当前进程的地址空间
	struct shared_use_st *shared;
	shared = (struct shared_use_st *)shmat(shmid, (void *)0, 0);
	if((void *)-1 == shared)
	{
		perror("shmat error");
		return 0;
	}

	//从共享内存中读取数据
	printf("Memory attached at %p\n", (int *)shared);
	shared->written = 0;

	while(running)
	{
		if(shared->written != 0)
		{
			printf("you wrote: %s\n", shared->text);
			sleep(2);

			shared->written = 0;

			if(strncmp(shared->text, "end", 3) == 0)
				running = 0;
		}
		else 
			sleep(1);
	}

	//把共享内存从当前进程中分离
	if(shmdt(shared) == 1)
	{
		perror("shmdt error");
		return 0;
	}

	//删除共享内存
	if(shmctl(shmid, IPC_RMID, 0) == -1)
	{
		perror("shmctl error");
		return 0;
	}

	return 0;
}
