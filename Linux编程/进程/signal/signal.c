#include <stdio.h>
#include <signal.h>

void signhandle(int signum)
{
	if(SIGINT == signum)
		printf("Ctrl C\n");
	else if(SIGTSTP == signum)
		printf("Ctrl Z\n");
	else if(SIGKILL == signum)
		printf("kill -9\n");
}


int main(int argc, char *argv[])
{
	signal(SIGINT, signhandle);
	signal(SIGTSTP, signhandle);
	
	//SIGKILL的处理方式改变不了
	//signal(SIGKILL, signhandle)

	while(1);
	return 0;
}
