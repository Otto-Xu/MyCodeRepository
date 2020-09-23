/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head)
{
	if(!head)
		return NULL;

	struct ListNode *p = head;
	struct ListNode *q = head->next;
	struct ListNode *r = NULL;

	while(q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	head->next = NULL;
	head = p;

	return head;
}
