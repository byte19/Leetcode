/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* bstToGst(struct TreeNode* root){
    int temp=0;
    void postorder(struct TreeNode* root){
        
        if(root==NULL){
            return NULL;
        }
        postorder(root->right);
        temp += root->val;
        root->val = temp;
        postorder(root->left);
        
    }
    
    postorder(root);
    return root;
}