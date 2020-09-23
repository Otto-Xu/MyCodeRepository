#include "stack.h"

void StackInit(Stack *ps)
{
    assert(ps);
    ps->data = (int *)calloc(N, sizeof(int));
    ps->_capacity = N;
    ps->_top = 0;
}

void StackDestory(Stack *ps)
{
    assert(ps);
    if(ps->data)
    {
        ps->_top = 0;
        ps->_capacity = 0;
        free(ps->data);
    }
}

void StackPush(Stack *ps, int data)
{
    assert(ps);
    if(ps->_top >= ps->_capacity)
    {
        ps->_capacity *= 2;
        ps->data = (int *)realloc(ps->data, ps->_capacity * sizeof(int));
    }

    ps->data[ps->_top] = data;
    ++ps->_top;
}

void StackPop(Stack *ps)
{
    assert(ps);
    --ps->_top;
}

int StackTop(Stack *ps)
{
    assert(ps);
    return ps->data[ps->_top - 1];
}

int StackEmpty(Stack *ps)
{
    assert(ps);
    return ps->_top != 0;
}

int StackSize(Stack *ps)
{
    assert(ps);
    return ps->_top;
}

void StackPrint(Stack *ps)
{
    for(int i = 0; i < ps->_top; ++i)
    {   
        printf("%d ", ps->data[i]);
    }
    printf("\n");
}
