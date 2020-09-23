#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "shmdata.h"

int main(int argc, char *argv[])
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
	shmid = shmget(key, 1024, 0644|IPC_CREAT);
	if(-1 == shmid)
	{
		perror("shmget error");
		return 0;
	}

	//将共享内存连接到当前进程的地址空间
	struct shared_use_st *shared = NULL;
	shared = (struct shared_use_st *)shmat(shmid, (void *)0, 0);
	if((void *)-1 == shared)
	{
		perror("shmat error");
		return 0;
	}

	//向共享内存中写入数据
	printf("Memory attached at %p\n", (int *)shared);
	char buffer[BUFSIZ+1];

	while(running)
	{
		while(shared->written == 1)
		{
			sleep(1);
			printf("waiting...\n");
		}
	
		memset(buffer, 0, BUFSIZ);	
		printf("enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		buffer[strlen(buffer)-1] = '\0';
		strncpy(shared->text, buffer, TEXT_SZ);
		shared->written = 1;
		
		if(strncmp(buffer, "end", 3) == 0)
			running = 0;
	}

	//把共享内存从当前进程中分离
	if(shmdt(shared) == -1)
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

	sleep(2);

	return 0;
}
