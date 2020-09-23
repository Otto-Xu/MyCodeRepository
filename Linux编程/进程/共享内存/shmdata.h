#ifndef _SHMDATA_H_
#define _SHMDATA_H_

#define TEXT_SZ 2048
#define PATH "/tmp/"
#define PROJ_ID 200

struct shared_use_st
{
	int written;
	char text[TEXT_SZ];
};

#endif
