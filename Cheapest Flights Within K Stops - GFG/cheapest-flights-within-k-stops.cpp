//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        int m = flights.size();
        
        for(int i=0;i<m;i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>> pq;
        // {node,{cost,stops}}
        
        pq.push({src,{0,K}});
        
        while(!pq.empty()) {
            int from = pq.front().first;
            int cost = pq.front().second.first;
            int stops = pq.front().second.second;
            
            pq.pop();
            
            if(stops < 0) continue;
            
            for(auto to: adj[from]) {
                int node = to.first;
                int disCost = cost + to.second;
                if(stops >= 0 && disCost < dist[node]) {
                    dist[node] = disCost;
                    pq.push({node,{dist[node],stops-1}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends