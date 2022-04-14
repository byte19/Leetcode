/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode* temp = root;
    
    while(temp){
        if (temp->val == val)
        return temp;
        
        else if(temp->val > val)
        temp = temp->left;
        
        else
        temp = temp->right;
    }
    return NULL;
}