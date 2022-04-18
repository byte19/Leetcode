/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> array;
    int inorder(TreeNode* root){
            if(root==NULL)
            return 0;
            
            inorder(root->left);
            array.push_back(root->val);
            inorder(root->right);
            
            return 0;
        }
    
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root);
        return array[k-1];
    }
};