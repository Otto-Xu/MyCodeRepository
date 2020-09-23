#include "compress.h"

int main(int argc, char *argv[])
{
    memset(&header, 0, sizeof(header));
    memset(&tmp, 0, sizeof(tmp));

    compress("text.txt", "text.txt.zip");
    uncompress("text.txt.zip", "uncompress.txt");

    return 0;
}
