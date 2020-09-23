/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if(!head)
	return NULL;

	struct ListNode *prev = head;
	struct ListNode *del = head;

	while(prev->next)
	{
		del = prev->next;
		if(prev->val == del->val)
		{
			prev->next = del->next
			del->next = NULL;
			del = prev->next;
			continue;
		}

		prev = prev->next;
		del = del->next;;
	}

	return head;
}
