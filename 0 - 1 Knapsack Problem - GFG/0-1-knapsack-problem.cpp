//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int fun(int ind,int wt[],int val[],int n,int W,vector<vector<int>>& dp) {
        if(ind==n) return 0;
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int notTake = 0 + fun(ind+1,wt,val,n,W,dp);
        int take = 0;
        if(W >= wt[ind]) take = val[ind] + fun(ind+1,wt,val,n,W-wt[ind],dp);
        
        return dp[ind][W] = max(take,notTake);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int>(W+1,0));
       
       for(int ind=1;ind<=n;ind++) {
           for(int w = 1;w <= W;w++) {
                int notTake = 0 + dp[ind-1][w];
                int take = 0;
                if(w >= wt[ind-1]) take = val[ind-1] + dp[ind-1][w-wt[ind-1]];
                
                dp[ind][w] = max(take,notTake);
           }
       }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends