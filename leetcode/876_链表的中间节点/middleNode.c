struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{
    if(!head)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while(fast->next)
    {
        slow = slow->next;
        fast = fast->next->next?fast->next->next:fast->next;
    }

    return slow;
}
