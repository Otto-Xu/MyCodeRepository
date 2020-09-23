/**
* Definition for singly-linked list.  
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	if(head->next == NULL && n == 1)
		return NULL;

	struct ListNode *del = head;
	struct ListNode *prev = head;
	struct ListNode *tail = head;
	struct ListNode *tmp = head;
	int i = 0, length = 1;

	while(tmp->next != NULL)
	{
		length++;
		tmp = tmp->next;
	}
	if(length == n)
	{
		head = head->next;
		return head;
	}
	else
	{
		for(i = 0; i < n-1; i++)
		tail = tail->next;
	
		while(tail->next != NULL)
		{
			prev = del;
			tail = tail->next;
			del = del->next;
		}

		prev->next = del->next;
		del->next = NULL;

		return head; 
	}
}
