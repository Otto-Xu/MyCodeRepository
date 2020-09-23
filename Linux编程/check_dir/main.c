#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void check_dir(char *path)
{
	DIR *dir;
	dir = opendir(path);
	if(NULL == dir)
	{
		perror("open dir error");
		return ;
	}

	struct dirent *d;
	struct stat s;
	char name[32];

	while(d = readdir(dir))
	{
		int ret;
		if(strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
			continue;
		

	//	memset(name, 0, sizeof(name));
		sprintf(name, "%s/%s", path, d->d_name);
		ret = stat(name, &s);
		if(-1 == ret)
		{
			perror("stat error");
			continue;
		}
	
		if(S_ISREG(s.st_mode))
		{
			printf("%s: reg\n", name);
		}
		else if(S_ISDIR(s.st_mode))
		{
			printf("%s: dir\n", name);
			check_dir(name);
		}
	}
}

int main(int argc, char *argv[])
{
	if(access(argv[1], F_OK))
		mkdir(argv[1], 0777);

	check_dir(argv[1]);

	return 0;
}
