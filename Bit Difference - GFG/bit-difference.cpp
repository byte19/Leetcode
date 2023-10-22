//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        int mod = 1e9 + 7;
        int ans = 0;
        for(int bit=0; bit<32;bit++) {
            long long oneCnt = 0, zerCnt = 0;
            for(int i=0;i<N;i++) {
                int mod2 = A[i]%2;
                A[i]/=2;
                if(mod2) oneCnt++;
                else zerCnt++;
            }
            ans = (ans + (((oneCnt*2)%mod)*zerCnt)%mod)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends