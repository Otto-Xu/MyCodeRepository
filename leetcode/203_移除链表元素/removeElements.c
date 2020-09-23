/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    菜的令人发指
    存在引用空指针的风险
    很多空指针都没去判断
*/

struct ListNode* removeElements(struct ListNode* head, int val){
     
    if(head == NULL)
        return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(head != NULL && slow != NULL && fast != NULL && head->val == val)
    {
        head = head->next;
        slow = head;
        fast->next = NULL;
        fast = head;
    }

    if(slow != NULL && slow->next != NULL)
        fast = slow->next;

    while(slow != NULL && fast != NULL)
    {
        if(fast->val == val)
        {
            slow->next = fast->next;
            fast->next = NULL;
            fast = slow->next;
        }
        else
        {
            slow = slow->next;
            if(slow != NULL && slow->next != NULL)
                fast = slow->next;
        }
    }    

    return head;
}
