#include <stdio.h>

#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__)

void testfun()
{	
	printf("\033[31m This text is red \033[0m This text has default color\n");
	dprintf("this is a test for dprintf\n");
}

int main(int argc, char *argv[])
{
	testfun();
	return 0;
}
