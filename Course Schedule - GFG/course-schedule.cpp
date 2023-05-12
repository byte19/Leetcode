//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        int N = n;
        int P = m;
	   vector<vector<int>> adj(N,vector<int>(0,0));
	   for(int i=0;i<P;i++) {
	       adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	   }
	   int V = n;
	   vector<int> indeg(V,0);
	    
	    for(int i=0;i<V;i++) {
	        for(int j=0;j<adj[i].size();j++) indeg[adj[i][j]]++;
	    }
	   // for(int i=0;i<V;i++) printf("%d ",indeg[i]);
	   // return indeg;
	    
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++) {
	        if(indeg[i]==0) {
	            ans.push_back(i);
	            q.push(i);
	           // printf("%d",i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int curr = q.front();
	        q.pop();
	        for(auto adjNode: adj[curr]) {
	            indeg[adjNode]--;
	            if(indeg[adjNode]==0) {
	                q.push(adjNode);
	                ans.push_back(adjNode);
	            }
	        }
	    }
	    if(ans.size()==N) return ans;
	    return {};
	   // if(ans.size()==V) return true;
	   // return false;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends