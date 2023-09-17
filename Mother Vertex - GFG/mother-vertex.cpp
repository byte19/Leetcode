//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int node,vector<int> adj[],int V,stack<int>& st,vector<int>& vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it,adj,V,st,vis);
        }
        st.push(node);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++) {
	        if(!vis[i]) {
	            dfs(i,adj,V,st,vis);
	        }
	    }
	    int mother = st.top();
	    while(!st.empty()) st.pop();
	    vector<int> vis2(V,0);
	    dfs(mother,adj,V,st,vis2);
	    
	    for(int i=0;i<V;i++) {
	        if(vis2[i]==0) return -1;
	    }
	    return mother;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends