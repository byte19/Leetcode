//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        if(grid[source.first][source.second]==0) return -1;
        
        vis[source.first][source.second] = 1;
        
        int ans = 1e9;
        queue<pair<pair<int,int>,int>> q;
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        q.push({{source.first,source.second},0});
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            
            if(i==destination.first && j==destination.second) {
                ans = min(ans,cost);
            }
            else {
                for(int k=0;k<4;k++) {
                    int nR = i + delRow[k];
                    int nC = j + delCol[k];
                    
                    if(nR >= 0 && nR < n && nC >= 0 && nC < m && vis[nR][nC]==0 && grid[nR][nC]==1) {
                        vis[nR][nC] = 1;
                        q.push({{nR,nC},cost+1});
                    } 
                }
            }
            
        }
        
        if(ans==1e9) return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends