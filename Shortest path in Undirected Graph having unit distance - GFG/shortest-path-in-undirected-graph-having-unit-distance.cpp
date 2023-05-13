//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node,unordered_map<int,vector<int>>& adj,vector<int>& ans,int vis[],int N,int M,int last_vertex,int cost) {
        vis[node] = 1;
        for(auto adjNode: adj[node]) {
            if(adjNode!=last_vertex && vis[adjNode]==0) {
                dfs(adjNode,adj,ans,vis,N,M,node,cost+1);
            }
        }
        ans[node] = min(ans[node],cost);
        vis[node] = 0;
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<M;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(N,1e9);
        ans[src]=0;
        int vis[N] = {0};
        dfs(src,adj,ans,vis,N,M,-1,0);
        // return {0,1,2,1,2,3,3,4,4};
        for(int i=0;i<N;i++) {
            if(ans[i]==1e9) ans[i]=-1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends