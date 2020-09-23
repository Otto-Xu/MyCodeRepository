#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>

#include "thread_pool.h"
#define BUFFSIZE 1024*8

struct file_name
{
	char src_file[128];
	char dst_file[128];
};

int copyfile(char *src, char *dst)
{	
	//dprintf("src_file: %s\n", src);
	//dprintf("dst_file: %s\n", dst);
	
	int fd_src, fd_dst;
	fd_src = open(src, O_RDONLY);
	if(fd_src == -1)
	{
		perror("fd_src open error");
		return -1;
	}
	fd_dst = open(dst, O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fd_dst == -1)
	{
		perror("fd_dst open error");
		return -1;
	}

	char buf[BUFFSIZE];

	int ret = -1;
	while(1)
	{
		ret = read(fd_src, buf,BUFFSIZE);
		if(ret == 0)
			break;
		else if(ret == -1)
		{
			perror("read error");
			break;
		}

		ret = write(fd_dst, buf, ret);
		if(ret == -1)
		{
			perror("write error");
			break;
		}
	}

	close(fd_src);
	close(fd_dst);

	return 0;
}

void *mytask(void *arg)
{
	struct file_name *fn = (struct file_name *)arg;
	//dprintf("fn->src_file: %s\n", fn->src_file);
	//dprintf("fn->dst_file: %s\n", fn->dst_file);

	copyfile(fn->src_file, fn->dst_file);

	return NULL;
}

void copydir(thread_pool *pool, const char *dir_src, const char *dir_dst)
{
	//打开目录
	DIR *dir = opendir(dir_src);
	if(NULL == dir)
	{
		perror("open dir_src error");
		return ;
	}

	struct dirent *d;
	struct stat s;
	char name[128];

	//遍历目录
	while(d = readdir(dir))
	{
		int ret;

		if(strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
			continue;
		
		memset(name, 0, sizeof(name));
		sprintf(name, "%s/%s", dir_src, d->d_name);

		ret = stat(name, &s);
		if(-1 == ret)
		{
			perror("stat error");
			continue;
		}

		if(S_ISDIR(s.st_mode))  //该子文件是目录文件
		{
			char new_dir_name[128];
			memset(new_dir_name, 0, 128);
			sprintf(new_dir_name, "%s/%s", dir_dst, d->d_name);
			if(access(new_dir_name, F_OK))
			{
				int ret;
				ret = mkdir(new_dir_name, 0777);
				if(ret == -1)
					perror("mkdir error");
			}

			copydir(pool, name, new_dir_name);
		}
		else if(S_ISREG(s.st_mode))  //该子文件是普通文件
		{
			char new_file_name[128];
			memset(new_file_name, 0, 128);
			sprintf(new_file_name, "%s/%s", dir_dst, d->d_name);

			struct file_name *fn = (struct file_name *)malloc(sizeof(struct file_name));
			strncpy(fn->src_file, name, strlen(name)+1);
			strncpy(fn->dst_file, new_file_name, strlen(new_file_name)+1);
			//dprintf("fn->src_file: %s\n", fn->src_file);
			//dprintf("fn->dst_file: %s\n", fn->dst_file);

			//添加任务到线程池
			add_task(pool, mytask, (void *)fn);
		}
	}

	//关闭目录
	closedir(dir);
}

int main(int argc, char **argv)
{
	if(argc != 3)
		exit(0);

	//初始化线程池
	thread_pool *pool = (thread_pool *)malloc(sizeof(thread_pool));
	init_pool(pool, 3);

	struct stat *file_info = calloc(1, sizeof(struct stat)); //malloc
	stat(argv[1], file_info);

	//执行任务
	if(S_ISREG(file_info->st_mode))
	{
		int fd[2];
		fd[0] = open(argv[1], O_RDONLY);
		fd[1] = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);
	
		add_task(pool, mytask, (void *)fd);
	}
	else if(S_ISDIR(file_info->st_mode))
	{
		if(access(argv[2], F_OK))
		{
			mkdir(argv[2], 0777);
		}

		copydir(pool, argv[1], argv[2]);
	}
	else
		printf("file format is NOT supported.\n");

	//销毁线程池
	destroy_pool(pool);

	return 0;
}
