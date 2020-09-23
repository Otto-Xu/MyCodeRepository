#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"

void my_printf_list(LIST *l)
{
	if(NULL == l)
	{
		dprintf("param error\n");
		return ;
	}

	NODE *tmp;
	tmp = l->head_node;

	while(tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	return ;
}


LIST *create_list()
{	
	LIST *l;
	l = (LIST *)malloc(sizeof(LIST));

	l->head_node = NULL;
	l->tail_node = NULL;
	l->len = 0;

	return l;
}


void tail_insert(LIST *l, NODE new)
{
	if(NULL == l)
	{
		dprintf("param error\n");
		return ;
	}

	NODE *tmp;
	tmp = (NODE *)malloc(sizeof(NODE));
	tmp->next = NULL;
	tmp->pre = NULL;

	tmp->data = new.data;

	if(0 == l->len)
	{
		l->head_node = tmp;
		l->tail_node = tmp;
		l->len++;
		return ;
	}

	l->tail_node->next = tmp;
	tmp->pre = l->tail_node;
	l->tail_node = tmp;
	l->len++;

	return ;
}


void destroy_node(LIST *l, int del_data)
{
	if(NULL == l)
	{
		dprintf("param error\n");
		return ;
	}
	
	NODE *tmp;
	if(l->head_node->data == del_data)
	{
		tmp = l->head_node;
		l->head_node = l->head_node->next;
		l->head_node->pre = NULL;
		tmp->next = NULL;
		tmp->pre = NULL;
		l->len--;
		free(tmp);
		tmp = NULL;
		return ;
	}
	else if(l->tail_node->data == del_data)
	{
		tmp = l->tail_node;
		l->tail_node = l->tail_node->pre;
		l->tail_node->next = NULL;
		tmp->next = NULL;
		tmp->pre = NULL;
		l->len--;
		free(tmp);
		tmp = NULL;
		return ;
	}

	tmp = l->head_node;
	while(tmp)
	{
		if(tmp->data == del_data)
		{
			tmp->pre->next = tmp->next;
			tmp->next->pre = tmp->pre;
			tmp->next = NULL;
			tmp->pre = NULL;
			l->len--;
			free(tmp);
			tmp = NULL;
			return ;
		}
		tmp = tmp->next;
	}
	
	printf("the node not exist\n");
	return ;
}


void destroy_list(LIST *l)
{
	if(NULL == l)
	{
		perror("param error\n");
		return ;
	}

	while(l->head_node && l->head_node->next)
	{
		NODE *tmp = l->head_node;
		l->head_node = l->head_node->next;

		tmp->next = NULL;
		tmp->pre = NULL;

		free(tmp);
	}

	l->head_node->next = NULL;
	l->head_node->pre = NULL;
	free(l);
	l = NULL;
	printf("delete list\n");

	return ;
}
