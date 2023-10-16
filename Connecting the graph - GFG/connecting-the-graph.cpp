//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    int extra = 0;
    int findPar(int node) {
        if(node == parent[node]) return node;
        
        return parent[node] = findPar(parent[node]);
    }
    void findUnion(int u,int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        
        if(ulp_u == ulp_v) {
            // extra+=1;   
            return;
        }
        if(rank[ulp_u] == rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += 1;
        }
        else if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        
        else parent[ulp_u] = ulp_v;
    }
    int Solve(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i] = i;
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if(findPar(u) != findPar(v)) {
                findUnion(u,v);
            }
            else extra++;
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++) cnt+= (parent[i]==i)?1:0;
        return (extra >= cnt-1)?(cnt-1):-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends