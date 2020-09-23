#include "stack.h"

int main(int argc, char *argv[])
{
    Stack s;
    Stack *p = &s;
    StackInit(p);
    
    int i = 0;
    for(i = 0; i < 20; i++)
    {
        StackPush(p, i);
    }
    StackPrint(p);
    
    StackPush(p, 100);
    StackPrint(p);

    StackPop(p);
    StackPrint(p);

    return 0;
}
