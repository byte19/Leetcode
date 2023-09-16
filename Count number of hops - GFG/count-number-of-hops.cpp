//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1e9 + 7;
    //Function to count the number of ways in which frog can reach the top.
    long long fun(int n, vector<int> &dp) {
        if(n==0) return 1;
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = (fun(n-1,dp) + fun(n-2,dp) + fun(n-3,dp))%mod;
    }
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        
        return fun(n,dp); 
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends