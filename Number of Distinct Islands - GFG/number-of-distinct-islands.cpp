//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,set<vector<pair<int,int>>>& s,int n,int m) {
        vector<pair<int,int>> temp;
        queue<pair<int,int>> q;
        q.push({i,j});
        temp.push_back({i,j});
        vis[i][j] = 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            for(int k=0;k<4;k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];
                
                if(nr >=0 && nr < n && nc >=0 && nc < m && vis[nr][nc]==0 && grid[nr][nc]==1) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                    temp.push_back({nr,nc});
                }
            }
        }
        // for(int i=0;i<temp.size();i++) {
        //     printf("{%d,%d}",temp[i].first,temp[i].second);
        // }
        // printf("\n");
        vector<pair<int,int>> t1;
        for(int k=0;k<temp.size();k++) {
            int nCordr = temp[k].first - temp[0].first;
            int nCordc = temp[k].second - temp[0].second;
            t1.push_back({nCordr,nCordc});
        }
        s.insert(t1);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> s; //to store distinct islands
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && vis[i][j]==0) {
                    bfs(i,j,grid,vis,s,n,m);
                }
            }
        }
        return s.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends