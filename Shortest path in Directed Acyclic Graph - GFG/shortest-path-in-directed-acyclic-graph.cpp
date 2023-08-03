//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> cost(N,1e9);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto edge: edges) adj[edge[0]].push_back({edge[1],edge[2]});
        queue<pair<int,int>> q;
        q.push({0,0});
        cost[0] = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int c = it.second;
            for(auto t: adj[node]) {
                int d = t.first;
                int co = t.second;
                if(cost[d] > co+c) {
                    cost[d] = co+c;
                    q.push({d,co+c});
                }
            }
        }
        for(int i=0;i<N;i++) {
            if(cost[i]==1e9) cost[i] = -1;
        }
        return cost;
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