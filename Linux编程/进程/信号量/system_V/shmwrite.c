#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "shmdata.h"
#include "semdata.h"

int main(int argc, char *argv[])
{
	int running = 1;

	//建立共享内存和信号量的IPC通讯
	key_t shmkey, semkey;
	shmkey = ftok(SHM_PATH, SHM_PROJ_ID);
	if(-1 == shmkey)
	{
		perror("shmkey ftok error");
		return 0;
	}
	semkey = ftok(SEM_PATH, SEM_PROJ_ID);
	if(-1 == semkey)
	{
		perror("semkey ftok error");
		return 0;
	}

	//创建共享内存和信号量
	int shmid, semid;
	shmid = shmget(shmkey, 1024, 0644|IPC_CREAT);
	if(-1 == shmid)
	{
		perror("shmid shmget error");
		return 0;
	}
	semid = semget(semkey, 1, 0644|IPC_CREAT);
	if(-1 == semid)
	{
		perror("semid shmget error");
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

	//初始化信号量
	union semun un;
	un.val = 1;
	if(semctl(semid, 0, SETVAL, un) == -1)
	{
		perror("semctl error");
		return 0;
	}

	/*信号量的P操作*/  
	void p()  
	{  
		struct sembuf sem_p;  
		sem_p.sem_num=0;  
		sem_p.sem_op=-1;  
		if(semop(semid,&sem_p,1)==-1)  
			printf("p operation is fail/n");          
	}  
	
	/*信号量的V操作*/  
	void v()  
	{  
		struct sembuf sem_v;  
		sem_v.sem_num=0;  
		sem_v.sem_op=1;  
		if(semop(semid,&sem_v,1)==-1)  
			printf("v operation is fail/n");  
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
		
		p();

		strncpy(shared->text, buffer, TEXT_SZ);
		shared->written = 1;

		//退出条件
		if(strncmp(buffer, "end", 3) == 0)
			running = 0;

		v();
	}
	
	//把共享内存从当前进程中分离
	if(shmdt(shared) == -1)
	{
		perror("shmdt error");
		return 0;
	}
	
	sleep(2);

	//shmread.c已经删除共享内存和信号量，这里无需实现
	/*
	//删除共享内存
	if(shmctl(shmid, IPC_RMID, 0) == -1)
	{
		perror("shmctl error");
		return 0;
	}

	//删除信号量
	if(semctl(semid, 0, IPC_RMID, un) == -1)
	{
		perror("semctl error");
		return 0;
	}
	*/

	return 0;
}
