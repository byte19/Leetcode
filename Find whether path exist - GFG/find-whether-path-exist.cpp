//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    vis[i][j] = 1;
                    break;
                }
            }
        }
        int newRow[] = {-1,0,1,0};
        int newCol[] = {0,1,0,-1};
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int row = it.first;
            int col = it.second;
            
            if(grid[row][col]==2) return true;
            
            for(int k=0;k<4;k++) {
                int nr = row + newRow[k];
                int nc = col + newCol[k];
                
                
                if(nr < n && nr >=0 && nc < n && nc >=0 && grid[nr][nc]!=0 && vis[nr][nc]==0) {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends