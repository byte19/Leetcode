//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int fun(int i,int j,string A,int n,vector<vector<int>>& dp) {
        if(i>j) return 0;
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(A[i]==A[j]) return dp[i][j] = 2 + fun(i+1,j-1,A,n,dp);
        else return dp[i][j] = max(fun(i+1,j,A,n,dp),fun(i,j-1,A,n,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fun(0,n-1,A,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends