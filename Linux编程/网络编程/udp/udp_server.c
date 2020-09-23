#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>


int sock_fd;

int main(int argc, char *argv[])
{
	sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == sock_fd)
	{
		perror("socket error");
		return 0;
	}

	struct sockaddr_in in;
	in.sin_family = AF_INET;

	in.sin_addr.s_addr = inet_addr(argv[1]);
	in.sin_port = htons(atoi(argv[2]));

	int ret;
	ret = bind(sock_fd, (struct sockaddr *)&in, sizeof(struct sockaddr));
	if(-1 == ret)
	{
		perror("bind error");
		return 0;
	}

	struct sockaddr_in cli;
	while(1)
	{
		char buf[100];
		memset(buf, 0, sizeof(buf));

		int cli_len = sizeof(struct sockaddr);
		ret = recvfrom(sock_fd, buf, sizeof(buf), MSG_DONTWAIT, 
		               (struct sockaddr *)&cli, &cli_len);

		if(ret > 0)
		{
			printf("[ip: %s, port: %d] %s\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port), buf);
		}
	}

	return 0;
}

