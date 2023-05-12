//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,vector<int> graph[],vector<int>& vis,vector<int>& pathVis,int V) {
        vis[i]=1;
        pathVis[i]=1;

        for(auto it: graph[i]) {
            if(!vis[it]) dfs(it,graph,vis,pathVis,V);
            
            else if(pathVis[it]==1 || vis[it]==2) {
                for(int j=0;j<V;j++) {
                    if(pathVis[j]==1) vis[j]=2;
                }
            }
        }
        pathVis[i]=0;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // int V = adj.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,-1);

        for(int i=0;i<V;i++) {
            if(!vis[i]) dfs(i,adj,vis,pathVis,V);
        }
        vector<int> ans;
        for(int i=0;i<V;i++) {
            if(vis[i]!=2) ans.push_back(i);
        } 
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends