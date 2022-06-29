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
    bool res = false;
    
    void solve(TreeNode* root,int target){
        if(root->left==NULL && root->right==NULL){
            target-=root->val;
            if(target==0) res = true;
            return;
        }
        
        if(root->left !=NULL) solve(root->left,target - root->val);
        if(root->right !=NULL) solve(root->right,target - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return res;
        solve(root,targetSum);
        return res;
    }
};