/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */    
struct TreeNode* convertBST(struct TreeNode* root){
    int sum_val = 0;
    int newOrder(struct TreeNode* root){
        
        if(root==NULL)
        return 0;
        
        newOrder(root->right);
        
        sum_val = sum_val + root->val;
        root->val = sum_val;
        
        newOrder(root->left);
        
        return 0;
    }
    
    newOrder(root);
    return root;
    
}