/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    bool ret; 

    if(p == NULL && q == NULL)
        return true;
    else if((p != NULL && q == NULL) || (p == NULL && q != NULL))
        return false;
    else    
    {
        ret = p->val == q->val ? true : false;
        return ret & isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
    }
    
    return false;
}
