#ifndef __SHMDATA_H__
#define __SHMDATA_H__

#define TEXT_SZ 2048
#define SHM_PATH "/tmp"
#define SHM_PROJ_ID 200

struct shared_use_st
{
	int written;
	char text[TEXT_SZ];
};

#endif
