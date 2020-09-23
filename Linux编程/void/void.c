#include <stdio.h>
#include <stdlib.h>

/********************************** 
 * Fuction : add
 * descir :  加法的相关数据及处理办法 
 **********************************/ 
typedef struct _tag_Add
{
    int a;
    int b;
    int result;
}sAdd;

void Add(void *param)
{
    sAdd *p = (sAdd *) param;
    p->result = p->a + p->b;
}

/********************************** 
 * Fuction : add
 * descir :  乘法的相关数据及处理办法 
 **********************************/ 
typedef struct _tag_Mul
{
    float a;
    float b;
    float result;
}sMul;

void Mul(void *param)
{
    sMul *p = (sMul *) param;
    p->result = p->a * p->b;
}

/************************************* 
 * Fuction : sCal
 * descir :  公共的调用接口 
 ************************************/ 
void sCal(void *param,void *fuc)
{
    ((void (*)(void*))fuc)(param);
}

int main(void)
{
    sAdd stAdd;
    sMul stMul;

    //数据初始化 
    stAdd.a = 10;
    stAdd.b = 20;

    stMul.a = 5;
    stMul.b = 5;
    //接口直接用 
    sCal(&stAdd,Add);
    sCal(&stMul,Mul);
	
	//对应的输出 
    printf("a + b = %d\n",stAdd.result);
    printf("a * b = %f\n",stMul.result);
    printf("公众号:最后一个bug\n");
    return 0;
} 