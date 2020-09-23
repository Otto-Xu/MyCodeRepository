#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>      
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/un.h>
#include <stddef.h>

#define UNIX_PATH "/tmp/1.socket"
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int sock_fd;
	sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(-1 == sock_fd)
	{
		perror("socket error");
		return 0;
	}

	struct sockaddr_un un;
	un.sun_family = AF_UNIX;
	strcpy(un.sun_path, UNIX_PATH);

	int len;
	len = offsetof(struct sockaddr_un, sun_path) + sizeof(UNIX_PATH);

	char buf[BUFSIZE];
	connect(sock_fd, (struct sockaddr *)&un, len);
	while(1)
	{
		int ret;
		write(sock_fd, "hello", 5);
		ret = read(sock_fd, buf, 5);
		printf("buf: %s\n", buf);
		sleep(1);
	}

	close(sock_fd);
	return 0;
}
