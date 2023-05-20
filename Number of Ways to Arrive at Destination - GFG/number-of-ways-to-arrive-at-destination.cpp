//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;
        int m = roads.size();
        
        for(int i=0;i<m;i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        vector<int> dist(n,2e9);
        dist[0] = 0;
        int ways[n] = {0};
        ways[0] = 1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // queue<pair<int,int>> pq;
        // {node,cost};
        
        pq.push({0,0});
        
        int ans = 0;
        
        while(!pq.empty()) {
            auto item = pq.top();
            int cost = item.first;
            int node = item.second;
            
            pq.pop();
            
            for(auto it: adj[node]) {
                int city = it.first;
                int newC = it.second + cost;
                
                if(newC < dist[city]) {
                    ways[city] = ways[node];
                    dist[city] = newC;
                    pq.push({newC,city});
                }
                else if(newC == dist[city]) {
                    ways[city] = ways[city] + ways[node];
                }
            }
        }
        return fmod(ways[n-1],1e9 + 7);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends