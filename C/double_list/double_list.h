#ifndef __LIST_H__
#define __LIST_H__

#define TRUE 0
#define FALSE -1

#define dprintf(format, ...) fprintf(stderr, "\033[31m[%s %s %d]\033[0m "format"", __FILE__    , __func__, __LINE__, ##__VA_ARGS__)

//结点
typedef struct node
{
	int data;
	struct node *next;
	struct node *pre;
}NODE;

//链表
typedef struct list
{
	NODE *head_node;
	NODE *tail_node;
	int len;
}LIST;


/*
	@brief 打印整个链表
	@param l 所要打印的链表头结点
*/
void my_printf_list(LIST *l);


/*
	@brief 创建一个链表
	@return 返回链表 
*/
LIST *create_list();


/*
	@brief 尾插法
	@param l 链表
	@param new 所要插入的节点
*/
void tail_insert(LIST *l, NODE new);


/*
	@brief 删除一个节点
	@param l 链表
	@param node 所要删除的节点
*/
void destroy_node(LIST *l, int del_data);


/*
	@brief 删除链表
	@param l 链表
*/
void destroy_list(LIST *l);
#endif
