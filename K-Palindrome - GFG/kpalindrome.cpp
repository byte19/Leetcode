//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


bool is_k_palin(string s,int k);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string s ;
		cin>>s;
		int k;
		cin>>k;
		
		cout<<is_k_palin(s,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function*/
int fun(int i,int j,string s,vector<vector<int>>& dp) {
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i-1]==s[j-1]) return dp[i][j] = 2 + fun(i+1,j-1,s,dp);
    else return dp[i][j] = max(fun(i+1,j,s,dp),fun(i,j-1,s,dp));
    
}
bool is_k_palin(string s,int k)
{
    int n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int lps = fun(1,s.size(),s,dp);
    
    return (s.size()-lps <= k);
}