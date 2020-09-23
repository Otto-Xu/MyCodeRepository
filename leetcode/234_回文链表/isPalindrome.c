/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    
    struct ListNode* tmp = head;
    int len = 0;
    while(tmp)
    {
        len++;
        tmp = tmp->next;
    }

    if(head != NULL)
        tmp = head;
    int *arr = (int *)malloc(sizeof(int) * (len/2));
    memset(arr, 0, sizeof(int) * (len/2));

    for(int i = 0; i < len/2; i++)
    {
        arr[i] = tmp->val;
        if(tmp->next != NULL)
            tmp = tmp->next;
    }

    if(len % 2 != 0 && tmp->next != NULL)
        tmp = tmp->next;

    for(int i = len/2 -1; i >= 0; i--)
    {
        if(arr[i] != tmp->val)
            return false;
        if(tmp->next != NULL)    
            tmp = tmp->next;    
    }

    return true;
}
