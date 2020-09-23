#include <poll.h>
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

#define MAX 1024
#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__) 

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
		return 0;
	}

	struct pollfd *fds;
	fds = (struct pollfd *)malloc(MAX*sizeof(struct pollfd));

	int *cli_fd;
	cli_fd = (int *)malloc(MAX*sizeof(int));

	int cli_num = 0;

	while(1)
	{
		fds[0].fd = sockfd;
		fds[0].events = POLLIN;
		fds[0].revents = 0;

		int i;
		for(i = 0; i < cli_num; i++)
		{
			fds[i+1].fd = cli_fd[i];
			fds[i+1].events = POLLIN;
			fds[i+1].revents = 0;
		}

		int ret;

		ret = poll(fds, MAX, 0);
		if(0 == ret)
			continue;
		else if(ret < 0)
		{
			perror("poll error");
			continue;
		}

		int new_fd;
		struct sockaddr_in cli;
		socklen_t len;

		if(fds[0].revents & POLLIN)
		{
			len = sizeof(cli);

			new_fd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if(new_fd > 0)
			{
				printf("A new connection: %s %d\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port));
				cli_fd[cli_num] = new_fd;
				cli_num++;
			}
		}

		for(i = 0; i < cli_num; i++)
		{
			if(fds[i+1].revents & POLLIN)
			{
				char rcv[32];
				memset(rcv, 0, sizeof(rcv));

				int num;
				num = read(fds[i+1].fd, rcv, sizeof(rcv));
				if(num > 0)
					printf("rcv: %s\n", rcv);
			}
		}
	}
}
