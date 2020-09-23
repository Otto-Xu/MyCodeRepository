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

	while(1)
	{
		sendto(sock_fd, "hello", 6, MSG_DONTWAIT, (struct sockaddr *)&in, sizeof(in));
		sleep(2);
	}

	return 0;
}
