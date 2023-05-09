//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int i,vector<int> adj[],vector<int>& vis,int V) {
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty()) {
            int curr = q.front().first;
            int last = q.front().second;
            q.pop();
            
            for(auto adjNode: adj[curr]) {
                if(vis[adjNode]==0) {
                    vis[adjNode] = 1;
                    q.push({adjNode,curr});
                }
                else if (last!=adjNode) return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++) {
            if(vis[i]==0) {
                if(bfs(i,adj,vis,V)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends