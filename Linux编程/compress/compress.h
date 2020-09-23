#ifndef __COMPRESS_H__
#define __COMPRESS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct head
{
    int b;
    long count;
    long parent, lch, rch;
    char bits[256];
};

struct head header[512], tmp;

void printPercent(int per);
int compress(const char *filename, const char *outputfile);
int uncompress(const char *filename, const char *outputfile);


#endif
