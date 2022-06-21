// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind,int w[],int v[],int W,vector<vector<int>>& dp){
        if(W==0) return 0;
        if(ind==0){
            if(W>=w[ind]) return v[ind];
            else return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int not_steal = 0 + solve(ind-1,w,v,W,dp);
        int steal = INT_MIN;
        if(W>=w[ind]) steal = v[ind] + solve(ind-1,w,v,W-w[ind],dp);
        
        return dp[ind][W] = max(steal,not_steal);
}   
        int knapSack(int W, int wt[], int val[], int n) 
        {
            vector<vector<int>> dp(n,vector<int>(W+1,-1));
        	return solve(n-1,wt,val,W,dp);
        }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends