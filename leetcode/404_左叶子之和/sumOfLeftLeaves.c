/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL)
        return 0;
    
    int result = 0;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        result += root->left->val;

    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + result;    

}
