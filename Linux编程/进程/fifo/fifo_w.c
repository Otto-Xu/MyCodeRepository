#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO "/tmp/test.fifo"

int main(int argc, char *argv[])
{
	int ret;

	if(access(FIFO, F_OK) != 0)
	{
		ret = mkfifo(FIFO, 0644);
		if(-1 == ret)
		{
			perror("create fifo error");
			return 0;
		}
	}

	int fd;
	fd = open(FIFO, O_RDWR);
	if(-1 == fd)
	{
		perror("open FIFO file error");
		return 0;
	}

	int cnt = 10;
	write(fd, &cnt, sizeof(cnt));

	close(fd);
	return 0;
}
