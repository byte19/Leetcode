//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> parent;
	vector<int> rank;
	int findPar(int node) {
	    if(node==parent[node]) return node;
	    
	    return parent[node] = findPar(parent[node]);
	}
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
    int numProvinces(vector<vector<int>> adj, int V) {
        parent.resize(V+1,0);
        rank.resize(V+1,0);
        for(int i=0;i<V;i++) parent[i] = i;
        
        for(int u=0;u<V;u++) {
            for(int v=0;v<V;v++) {
                if(adj[u][v]==1) {
                    findUnion(u,v);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<V;i++) cnt += (parent[i]==i)?1 : 0;
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends