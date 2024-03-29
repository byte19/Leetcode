//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> stack;
        vector<int> res;
        vector<int> vis(V,0);
        
        stack.push_back(0);
        
        while(stack.size() > 0) {
            int curr = stack.back();
            stack.pop_back();
            if(vis[curr]==1) continue;
            
            else {
                vis[curr] = 1;
                res.push_back(curr);
                for(int j=adj[curr].size()-1;j>=0;j--) stack.push_back(adj[curr][j]);
            }
        }
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends