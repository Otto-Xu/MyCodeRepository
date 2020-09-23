#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

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

	int cnt;
	ret = 0;
	while(ret <= 0)
	{
		//阻塞在read
		ret = read(fd, &cnt, sizeof(cnt));
		if(ret > 0)
		{
			printf("cnt: %d\n", cnt);
		}
		else
		{
			printf("nothing...\n");
		}
	}

	close(fd);
	sleep(2);
	return 0;
}
