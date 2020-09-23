#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <stddef.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 1024
#define UNIX_PATH "/tmp/1.socket"

typedef unsigned int _u32_t;

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

	int ret;
	ret = bind(sock_fd, (struct sockaddr *)&un, len);
	if(-1 == ret)
	{
		perror("bind error");
		return 0;
	}

	listen(sock_fd, 20);

	struct sockaddr_un cli_un;
	socklen_t cli_len;
	char buf[BUFSIZE];

	while(1)
	{
		int cli_fd, i;
		cli_len = sizeof(cli_un);
		cli_fd = accept(sock_fd, (struct sockaddr *)&cli_un, &len);
		if(cli_fd < 0)
			continue;

		while(1)
		{
			ret = read(cli_fd, buf, sizeof(buf));
			if(ret < 0)
			{
				perror("read error");
				break;
			}
			else if(ret == 0)
			{
				printf("EOF\n");
				break;
			}

			printf("received: %s\n", buf);

			for(i = 0; i < ret; i++)
			{
				buf[i] = toupper(buf[i]);
			}
			write(cli_fd, buf, ret);
		}
		close(cli_fd);
	}

	close(sock_fd);
	return 0;
}

