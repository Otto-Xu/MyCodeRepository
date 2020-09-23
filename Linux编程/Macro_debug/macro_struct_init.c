#include <stdio.h>

#define NewNode(a, b) {(add), (a), (b)}

typedef struct node {
	int (*func)(struct node*);
	int a;
	int b;
}NODE;

int add(NODE *test)
{
	return test->a + test->b;
}

int main(int argc, char* argv[])
{
	NODE test = NewNode(2, 3);
	printf("test.a = %d\ttest.b = %d\n", test.a, test.b);
	printf("add is %d\n", test.func(&test));
	return 0;
}