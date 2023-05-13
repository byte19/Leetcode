//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node,unordered_map<int,vector<vector<int>>>& adj,vector<int>& ans,int N,int M,int cost) {
        //  ans[node] = min(ans[node],cost);
         
         for(int j=0;j<adj[node].size();j++) {
             dfs(adj[node][j][0],adj,ans,N,M,cost + adj[node][j][1]);
         }
         ans[node] = min(ans[node],cost);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,vector<vector<int>>> adj;
        for(int i=0;i<M;i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<int> ans(N,1e9);
        ans[0] = 0;
        dfs(0,adj,ans,N,M,0);
        for(int i=0;i<N;i++) {
            if(ans[i]==1e9) ans[i]=-1;
        }
        return ans;
        // return {0,1,3,4,3};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends