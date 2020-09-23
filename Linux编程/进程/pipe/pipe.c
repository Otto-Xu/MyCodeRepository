#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	int ret;

	ret = pipe(pipefd);
	if(-1 == ret)
	{
		perror("create pipe error/n");
		return 0;
	}

	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		printf("hello I am father ...\n");
		//wait(NULL);
		//printf("my son was terminated ...\n");
		int cnt = 100;
		close(pipefd[0]);
		write(pipefd[1], &cnt, sizeof(cnt));
		wait(NULL);
		printf("my son was terminated ...\n");
	}
	else if(pid == 0)
	{
		printf("hello I am son ...\n");
		close(pipefd[1]);

		int cnt;
		int ret;
		ret = read(pipefd[0], &cnt, sizeof(cnt));
		if(ret > 0)
			printf("son read: %d\n", cnt);
		else
			printf("I have read nothing ...\n");
	}
	else if(pid < 0)
	{
		perror("fork error\n");
		return 0;
	}

	return 0;
}
