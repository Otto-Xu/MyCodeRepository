#ifndef __SEMDATA_H__
#define __SEMDATA_H__

#define SEM_PATH "/home"
#define SEM_PROJ_ID 250

union semun{
	int val;
	unsigned short *array;
	struct seminfo *__buf;
};

#endif
