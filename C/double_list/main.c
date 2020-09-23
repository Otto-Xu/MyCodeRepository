#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_list.h"

int main(int argc, char *argv[])
{
	LIST *l = NULL;
	l = create_list();
	if(NULL == l)
	{
		dprintf("create list error !\n");
		return FALSE;
	}

	int i;
	for(i = 0; i < 3; i++)
	{
		NODE new;
		new.data = i;
		tail_insert(l, new);
	}

	my_printf_list(l);

	int del_data;
	scanf("%d", &del_data);

	destroy_node(l, del_data);
	
	my_printf_list(l);

	destroy_list(l);

	return 0;
}
