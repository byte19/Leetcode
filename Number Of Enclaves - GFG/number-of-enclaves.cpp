//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(),n = grid[0].size();
        int totOnes = 0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]==1) totOnes+=1;

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++) for(int j=0;j<n;j++) if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1) q.push({i,j}),vis[i][j]=1;

        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        int boundOnes = 0;
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(grid[row][col]==1) boundOnes++;
            for(int i=0;i<4;i++) {
                int nr = row + delrow[i];
                int nc = col + delcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return totOnes - boundOnes;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends