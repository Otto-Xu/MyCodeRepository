#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__)

int cnt;

//树的结点
typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE;

//创建一颗二分查找树
void bst_tree(NODE **tree, int data)
{
	if(*tree == NULL)
	{
		*tree = (NODE *)malloc(sizeof(NODE));
		(*tree)->data = data;
		(*tree)->lchild = NULL;
		(*tree)->rchild = NULL;
		return;
	}

	if(data == (*tree)->data)
		return ;
	
	if(data < (*tree)->data)
		bst_tree(&((*tree)->lchild), data);
	if(data > (*tree)->data)	
		bst_tree(&((*tree)->rchild), data);
}

//先序
void pre_order(NODE **tree)
{
	if(*tree == NULL)
		return ;
	
	printf("%d ", (*tree)->data);
	pre_order(&((*tree)->lchild));
	pre_order(&((*tree)->rchild));
}

//后序
void epilogue(NODE **tree)
{
	if(*tree == NULL)
		return;
	
	epilogue(&((*tree)->lchild));
	epilogue(&((*tree)->rchild));
	printf("%d ", (*tree)->data);
}


//中序
void infix_order(NODE **tree)
{
	if(*tree == NULL)
		return ;
	infix_order(&((*tree)->lchild));
	printf("%d ", (*tree)->data);
	infix_order(&((*tree)->rchild));
}

//求树的高度
int bst_tree_deep(NODE **tree)
{
	int deep = 0;

	int ldeep = 1, rdeep = 1;
	if(*tree != NULL)
	{
		ldeep += bst_tree_deep(&((*tree)->lchild));
		rdeep += bst_tree_deep(&((*tree)->rchild));

		if(ldeep >= rdeep)
			deep = ldeep;
		else
			deep = rdeep;
	}

	return deep;
}

int main(int argc, char *argv[])
{
	NODE *tree;
	tree = NULL;

	int i;
	int data;
	for(i = 0; i < 13; i++)
	{
		scanf("%d", &data);
		bst_tree(&tree, data);
	}
	
	dprintf("after bst_tree\n");

	pre_order(&tree);
	printf("\n");

	epilogue(&tree);
	printf("\n");

	infix_order(&tree);
	printf("\n");

	printf("deep: %d\n", bst_tree_deep(&tree));

	return 0;
}
