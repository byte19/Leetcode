//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        for(int j=wt[0];j<=W;j++) dp[0][j] = (j/wt[0])*val[0];
        // return fun(N-1,W,val,wt,dp);
        
        for(int ind = 1;ind<N;ind++) {
            for(int w = 0; w <= W; w++) {
                int notTake = dp[ind-1][w];
                int take = 0;
                if(w>=wt[ind]) take = val[ind] + dp[ind][w-wt[ind]];
                
                dp[ind][w] = max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends