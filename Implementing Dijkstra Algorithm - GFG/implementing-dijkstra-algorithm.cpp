//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // unordered_map<int,vector<pair<int,int>>> AdjList;
        // for(int i=0;i<V;i++) {
        //     AdjList[adj[i][0]].push(back)
        // }
        vector<int> cost(V,1e9);
        cost[S] = 0;
        queue<pair<int,int>> q;
        q.push({S,0});
        while(!q.empty()) {
            int node = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(auto it: adj[node]) {
                if((c + it[1]) < cost[it[0]]) {
                    cost[it[0]] = c+it[1];
                    q.push({it[0],c+it[1]});
                }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends