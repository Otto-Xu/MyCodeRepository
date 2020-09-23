#include "compress.h"

char *myitoa(int num,char *str,int radix) 
{  
	/* 索引表 */ 
	char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	unsigned unum; /* 中间变量 */ 
	int i=0,j,k; 
	/* 确定unum的值 */ 
	if(radix==10&&num<0) /* 十进制负数 */ 
	{ 
		unum=(unsigned)-num; 
		str[i++]='-'; 
	} 
	else unum=(unsigned)num; /* 其他情况 */ 
	/* 逆序 */ 
	do  
	{ 
		str[i++]=index[unum%(unsigned)radix]; 
		unum/=radix; 
	}while(unum); 
	str[i]='\0'; 
	/* 转换 */ 
	if(str[0]=='-') k=1; /* 十进制负数 */ 
	else k=0; 
	/* 将原来的“/2”改为“/2.0”，保证当num在16~255之间，radix等于16时，也能得到正确结果 */ 
	char temp; 
	for(j=k;j<=(i-k-1)/2.0;j++) 
	{ 
		temp=str[j]; 
		str[j]=str[i-j-1]; 
		str[i-j-1]=temp; 
	} 
	return str; 
} 

void printPercent(int per)
{
    int i = 0;
    printf("|");
    for(i = 0; i < 10; i++)
    {
        if(i < per/10)
            printf(">");
        else
            printf("<");
    }
    printf("|已完成%d%%\n", per);
}


int compress(const char *filename, const char *outputfile)
{
    char buf[512];
    unsigned char c;
    long i, j, m, n, f;
    long min1, pt1, flength;
    FILE *ifp, *ofp;
    int per = 10;

    ifp = fopen(filename, "rb");
    if(ifp == NULL)
    {
        printf("open file %s error !\n", filename);
        return 0;
    }

    ofp = fopen(outputfile, "wb+");
    if(ofp == NULL)
    {
        printf("open file %s error !\n", outputfile);
        return 0;
    }

    flength = 0;
    while(!feof(ifp))
    {
        fread(&c, 1, 1, ifp);
        header[c].count++;
        flength++;
    }
    flength--;
    header[c].count--;
    for(i = 0; i < 512; i++)
    {
        if(header[i].count != 0)
            header[i].b = (unsigned char)i;
        else
            header[i].b = -1;

        header[i].parent = -1;
        header[i].lch = header[i].rch = -1;
    }

    for(i = 0; i < 256; i++)
    {
        for(j = i+1; j < 256; j++)
        {
            if(header[i].count < header[j].count)
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }

    for(i = 0; i < 256; i++)
    {
        if(header[i].count == 0)
            break;
    }

    n = i;
    m = 2 * n -1;

    for(i = n; i < m; i++)
    {
        min1 = 999999999;
        for(j = 0; j < i; j++)
        {
            if(header[j].parent != -1)
                continue;
            if(min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }

        header[i].count = header[pt1].count;
        header[pt1].parent = i;
        header[i].lch = pt1;
        min1 = 999999999;
        for(j = 0; j < i; j++)
        {
            if(header[j].parent != -1)
                continue;
            if(min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }

        header[i].count += header[pt1].count;
        header[i].rch = pt1;
        header[pt1].parent = i;
    }


    for(i = 0; i < n; i++)
    {
        f = i;
        header[i].bits[0] = 0;
        while(header[f].parent != -1)
        {
            j = f;
            f = header[f].parent;
            if(header[f].lch == j)
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '0';
            }
            else
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '1';
            }
        }
    }


    fseek(ifp, 0, SEEK_SET);
    fseek(ofp, 8, SEEK_SET);
    buf[0] = 0;
    f = 0;
    pt1 = 8;

    printf("读取将要压缩的文件：%s\n", filename);
    printf("当前文件有%ld字符\n", flength);
    printf("正在压缩\n");

    while(!feof(ifp))
    {
        c = fgetc(ifp);
        f++;
        for(i = 0; i < n; i++)
        {
            if(c == header[i].b)
                break;
        }

        strcat(buf, header[i].bits);
        j = strlen(buf);
        c = 0;
        while(j >= 8)
        {
            for(i = 0; i < 8; i++)
            {
                if(buf[i] == '1')
                    c = (c << 1) | 1;
                else
                    c = c << 1;
            }
            fwrite(&c, 1, 1, ofp);
            pt1++;
            strcpy(buf, buf + 8);
            j = strlen(buf);
        }

        if(100 * f/flength > per)
        {
            printPercent(per);
            per += 10;
        }

        if(f == flength)
            break;
    }

    printPercent(100);
    

    if(j > 0)
    {
        strcat(buf, "00000000");
        for(i = 0; i < 8; i++)
        {
            if(buf[i] == '1')
                c = (c << 1) | 1;
            else
                c = c << 1;
        }
        fwrite(&c, 1, 1, ofp);
        pt1++;
    }

    fseek(ofp, 0, SEEK_SET);
    fwrite(&flength, 1, sizeof(flength), ofp);
    fwrite(&pt1, sizeof(long), 1, ofp);
    fseek(ofp, pt1, SEEK_SET);
    fwrite(&n, sizeof(long), 1, ofp);
    for(i = 0; i < n; i++)
    {
        tmp = header[i];

        fwrite(&(header[i].b), 1, 1, ofp);
        pt1++;
        c = strlen(header[i].bits);
        fwrite(&c, 1, 1, ofp);
        pt1++;
        j = strlen(header[i].bits);

        if(j % 8 != 0)
        {
            for(f = j % 8; f < 8; f++)
                strcat(header[i].bits, "0");
        }

        while(header[i].bits[0] != 0)
        {
            c = 0;
            for(j = 0; j < 8; j++)
            {
                if(header[i].bits[j] == '1')
                    c = (c << 1) | 1;
                else
                    c = c << 1;
            }

            strcpy(header[i].bits, header[i].bits + 8);
            fwrite(&c, 1, 1, ofp);
                pt1++;
        }

        header[i] = tmp;
    }

    fclose(ifp);
    fclose(ofp);

    printf("压缩后文件为%s\n", outputfile);
    printf("压缩后文件有%ld字符\n", pt1 + 4);
    
    return 1;
}

int uncompress(const char *filename, const char *outputfile)
{
    char buf[255], bx[255];
    unsigned char c;
    char out_filename[512];
    long i, j, m, n, f, p, l;
    long flength;
    int per = 10;
    int len = 0;
    FILE *ifp, *ofp;
    char c_name[512] = {0};
    
    ifp = fopen(filename, "rb");
    if(ifp == NULL)
    {
        printf("open file %s error !\n", filename);
        return 0;
    }

    if(outputfile)
        strcpy(out_filename, outputfile);
    else
        strcpy(out_filename, c_name);

    ofp = fopen(out_filename, "wb");
    if(ofp == NULL)
    {
        printf("open file %s error !\n", out_filename);
        return 0;
    }

    fread(&flength, sizeof(long), 1, ifp);
    fread(&f, sizeof(long), 1, ifp);
    fseek(ifp, f, SEEK_SET);
    fread(&n, sizeof(long), 1, ifp);
    for(i = 0; i < n; i++)
    {
        fread(&header[i].b, 1, 1, ifp);
        fread(&c, 1, 1, ifp);
        p = (long)c;
        header[i].count = p;
        header[i].bits[0] = 0;
        if(p % 8 > 0)
            m = p / 8 + 1;
        else
            m = p / 8;
        for(j = 0; j < m; j++)
        {
            fread(&c, 1, 1, ifp);
            f = c;
           // printf("before myitoa f %ld\n", f);
            myitoa(f, buf, 2);
            f = strlen(buf);
            for(l = 8; l > f; l--)
            {
                strcat(header[i].bits, "0");
            }
            strcat(header[i].bits, buf);
        }
        header[i].bits[p] = 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(strlen(header[i].bits) > strlen(header[j].bits))
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }

    p = strlen(header[n-1].bits);
    fseek(ifp, 8, SEEK_SET);
    m = 0;
    bx[0] = 0;

    while(1)
    {
        while(strlen(bx) < (unsigned int)p)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            //printf("before myitoa f %ld\n", f);
            myitoa(f, buf, 2);
            f = strlen(buf);
            for(l = 8; l > f; l--)
            {
                strcat(bx, "0");
            }
            strcat(bx, buf);
        }
        for(i = 0; i < n; i++)
        {
            if(memcmp(header[i].bits, bx, header[i].count == 0))
                break;
        }
        strcpy(bx, bx + header[i].count);
        c = header[i].b;
        fwrite(&c, 1, 1, ofp);
        m++;

        if(100 * m / flength > per)
        {
            printPercent(per);
            per += 10;
        }
        if(m == flength)
            break;    
    }
    printPercent(100);

    fclose(ifp);
    fclose(ofp);

    printf("解压后文件为：%s\n", out_filename);
    printf("解压后文件有%ld字符\n", flength);

    return 1;
}
