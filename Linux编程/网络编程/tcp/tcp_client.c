#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__) 

int main(int argc, char *argv[])
{
	int sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		dprintf("create socket error !\n");
		return 0;
	}

	struct sockaddr_in in;
	in.sin_family = AF_INET;
	in.sin_port = htons(atoi(argv[2]));
	in.sin_addr.s_addr = inet_addr(argv[1]);

	socklen_t len;
	len = sizeof(in);

	int ret;
	while(1)
	{
		ret = connect(sockfd, (struct sockaddr *)&in, len);
		if(ret == 0)
			break;

		printf("connect failue\n");
	}

	while(1)
	{
		ret = send(sockfd, "hello", 6, 0);
		sleep(1);
	}

	return 0;
}
