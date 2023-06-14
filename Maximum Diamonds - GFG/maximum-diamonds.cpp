//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
        priority_queue<long long> pq;
        long long ans = 0;
        for(int i=0;i<N;i++) pq.push(A[i]);
        
        while(!pq.empty() && K!=0) {
            ans+=pq.top();
            int val = pq.top();
            pq.pop();
            val = val/2;
            if(val!=0) pq.push(val);
            
            K--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends