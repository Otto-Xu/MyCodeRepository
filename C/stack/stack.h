#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 10

typedef struct Stack
{
    int *data;
    int _top;
    int _capacity;
}Stack;

void StackInit(Stack *ps);
void StackDestory(Stack *ps);
void StackPush(Stack *ps, int data);
void StackPop(Stack *ps);
int StackTop(Stack *ps);
int StackEmpty(Stack *ps);
int StackSize(Stack *ps);
void StackPrint(Stack *ps);
