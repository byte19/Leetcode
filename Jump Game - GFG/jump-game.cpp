//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int nums[], int N) {
        int n = N;
        vector<int> dp(n,0);
        dp[n-1] = 1;
        for(int ind=n-2;ind>=0;ind--){
            bool temp = false;
            for(int i=1;i<=nums[ind];i++){
                if(ind+i < n) temp = temp || dp[ind+i];
                if(temp==1) break;
            }
            dp[ind] = temp;
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends