//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int P = prerequisites.size();
	   vector<vector<int>> adj(N,vector<int>(0,0));
	   for(int i=0;i<P;i++) {
	       adj[prerequisites[i].second].push_back(prerequisites[i].first);
	   }
	   int V = N;
	   int indeg[V] = {0};
	    
	    for(int i=0;i<V;i++) {
	        for(auto adjNode: adj[i]) indeg[adjNode]++;
	    }
	    
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<V;i++) {
	        if(indeg[i]==0) {
	            ans.push_back(i);
	            q.push(i);
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
	    if(ans.size()==V) return true;
	    return false;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends