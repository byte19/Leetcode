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
        vector<int> prev(W+1,0), curr(W+1,0);
        for(int j=wt[0];j<=W;j++) prev[j] = (j/wt[0])*val[0];
        // return fun(N-1,W,val,wt,dp);
        
        for(int ind = 1;ind<N;ind++) {
            for(int w = 0; w <= W; w++) {
                int notTake = prev[w];
                int take = 0;
                if(w>=wt[ind]) take = val[ind] + curr[w-wt[ind]];
                
                curr[w] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[W];
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