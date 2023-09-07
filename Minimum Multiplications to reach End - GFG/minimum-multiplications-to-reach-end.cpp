//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> cost(100000,1e9);
        cost[start] = 0;
        int ans = 1e9;
        int mod = 1e5;
        queue<pair<int,int>> q;
        q.push({start,0}); // { num, steps }
        
        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(node==end) ans = min(ans,steps);
            else {
                for(int i=0;i<arr.size();i++) {
                    int num = (node*arr[i])%mod;
                    if(1+steps <  cost[num]) {
                        cost[num] = 1+steps;
                        q.push({num,1+steps});
                    }
                }
            }
        }
        return (ans==1e9)?-1 : ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends