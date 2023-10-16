//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> parent;
	vector<int> rank;
	int findPar(int node) {
	    if(node==parent[node]) return node;
	    
	    return parent[node] = findPar(parent[node]);
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	void findUnion(int u,int v) {
	    int u_ulp = findPar(u);
	    int v_ulp = findPar(v);
	    
	    if(u_ulp==v_ulp) return;
	    
	    if(rank[u_ulp] == rank[v_ulp]) {
	        parent[u_ulp] = v_ulp;
	        rank[v_ulp]+=1;
	    }
	    else if(rank[u_ulp] > rank[v_ulp]) {
	        parent[v_ulp] = u_ulp;
	    }
	    else{
	        parent[u_ulp] = v_ulp;
	    }
	    
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        parent.resize(V+1,0);
        rank.resize(V+1,0);
        for(int i=0;i<V;i++) parent[i] = i;
        
        int cost = 0;
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<V; i++) {
            for(auto it : adj[i]) {
                int node = i;
                int u = it[0];
                int wt = it[1];
                edges.push_back({wt,{node,u}});
            }
        }
        sort(edges.begin(),edges.end());
        for(auto edge: edges) {
            int wt = edge.first;
            int u  = edge.second.first;
            int v  = edge.second.second;
            if(findPar(u)!=findPar(v)) {
                cost+=wt;
                findUnion(u,v);
            }
            
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends