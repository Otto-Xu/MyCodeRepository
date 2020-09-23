#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>


#define TRUE 0
#define FALSE -1
#define CLI_MAX_NUM 1023
#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__) 

void *func(void *arg)
{
	pthread_detach(pthread_self());

	char *buf;
	buf = (char *)arg;

	dprintf("read: %s\n", buf);

	free(buf);
}

int make_tcp_server(char *ip, unsigned short port)
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		dprintf("create socket error!\n");
		perror("error");
		return -1;
	}

	struct sockaddr_in in;
	in.sin_family = AF_INET;
	in.sin_port = htons(port);
	in.sin_addr.s_addr = inet_addr(ip);

	int ret;
	ret = bind(sockfd, (struct sockaddr *)&in, sizeof(in));
	if(-1 == ret)
	{
		dprintf("bind error!\n");
		perror("error");
		return -1;
	}

	listen(sockfd, 100);
	
	return sockfd;
}

int main(int argc, char *argv[])
{
	int sockfd;
	sockfd = make_tcp_server(argv[1], atoi(argv[2]));
	if(-1 == sockfd)
	{
		dprintf("make tcp server error !\n");
		return 0;
	}

	int max_fd;

	fd_set set;

	int cli_fd[CLI_MAX_NUM];

	int cli_num;

	cli_num = 0;
	max_fd = sockfd;

	while(1)
	{
		FD_ZERO(&set);

		FD_SET(sockfd, &set);

		int i;
		for(i = 0; i < cli_num; i++)
		{
			FD_SET(cli_fd[i], &set);
		}

		int ret;
		ret = select(max_fd+1, &set, NULL, NULL, NULL);
		if(ret <= 0)
			continue;

		int new_fd;
		struct sockaddr_in cli_in;
		socklen_t len;

		if(FD_ISSET(sockfd, &set))
		{
			len = sizeof(cli_in);
			new_fd = accept(sockfd, (struct sockaddr *)&cli_in, &len);
			dprintf("new client: %s %d\n", inet_ntoa(cli_in.sin_addr), ntohs(cli_in.sin_port));
			cli_fd[cli_num] = new_fd;
			cli_num++;

			if(new_fd > max_fd)
				max_fd = new_fd;
		}

		for(i = 0; i < cli_num; i++)
		{
			if(FD_ISSET(cli_fd[i], &set))
			{
				int n;

				char *buf;
				buf = (char *)malloc(1024);
				memset(buf, 0, 1024);

				n = read(cli_fd[i], buf, 1024);

				if(n <= 0)
					continue;

				pthread_t tid;
				pthread_create(&tid, NULL, func, (void *)buf);
			}
		}
	}

	return 0;
}
