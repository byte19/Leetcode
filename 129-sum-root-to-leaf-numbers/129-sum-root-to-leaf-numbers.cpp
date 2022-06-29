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
#include<bits/stdc++.h>
class Solution {
public:
    int res = 0;
    
    void solve(TreeNode* root,string s){
        if(root->left==NULL && root->right==NULL){
            s += to_string(root->val);
            res += stoi(s);
            return;
        }
        
        if(root->left) solve(root->left,s+to_string(root->val));
        if(root->right) solve(root->right,s+to_string(root->val));
    }
    
    int sumNumbers(TreeNode* root) {
        string s = "";
        solve(root,s);
        return res;
    }
};