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
    vector<vector<int>> res;
    void solve(TreeNode* root,int target,vector<int> ds){
        if(root->left==NULL && root->right==NULL){
            ds.push_back(root->val);
            int sum = 0;
            for(int x:ds) sum+=x;
            if(sum==target) res.push_back(ds);
            return;
        }
        ds.push_back(root->val);
        if(root->left != NULL) solve(root->left,target,ds);
        if(root->right != NULL) solve(root->right,target,ds);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return res;
        vector<int> ds;
        solve(root,targetSum,ds);
        return res;
    }
};