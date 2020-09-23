#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__) 

void *func(void *arg)
{
	char buf[1024];

	int ret;
	int cli_fd;

	cli_fd = *((int *)arg);

	while(1)
	{
		memset(buf, 0, sizeof(buf));

		ret = read(cli_fd, buf, sizeof(buf));
		if(ret > 0)
			printf("read: %s\n", buf);
	}
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

	struct sockaddr_in cli;
	socklen_t len;

	while(1)
	{
		int cli_fd;

		cli_fd = accept(sockfd, (struct sockaddr *)&cli, &len);
		if(cli_fd < 0)
			continue;

		dprintf("client: ip:%s, port:%u\n", 
				 inet_ntoa(cli.sin_addr), 
				 ntohs(cli.sin_port));

		pthread_t tid;
		pthread_create(&tid, NULL, func, (void *)&cli_fd);
	}

	return 0;
}
