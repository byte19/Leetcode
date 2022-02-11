/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    
    struct TreeNode* invert(struct TreeNode *root){
        if(root!=NULL){
            struct TreeNode *temp;
            temp = root->right;
            root->right = root->left;
            root->left = temp;
            
            invert(root->left);
            invert(root->right);
        }
        return NULL;
    }
    
        invert(root);
        return root;
}