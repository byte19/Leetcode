#include<bits/stdc++.h>

class Solution {
public:
	int res = 0;
	
	void solve(TreeNode* root,string s){
		if(root->left==NULL && root->right==NULL){
			s += to_string(root->val);  //converting int to string so that we can append leaf node value
			res += stoi(s);    //converting string to int
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