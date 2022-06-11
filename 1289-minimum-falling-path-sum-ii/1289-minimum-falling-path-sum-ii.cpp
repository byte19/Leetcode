class Solution { 
public: 
 
    int f(int row ,int column ,vector<vector<int>>& grid,int last,int n,vector<vector<int>>& dp ){ 
    if(row >= n) {
        return 0; 
    }
     int mini = 1e9;
    if(dp[row][column] != -1) return dp[row][column]; 
    for(int col=0; col<n; col++){ 
        if(col == last) continue; 
        int x = grid[row][col] + f(row+1,col,grid,col,n,dp); 
        mini = min(mini,x); 
    } 
    dp[row][column] = mini; 
    return mini; 
    } 
    
     int minFallingPathSum(vector<vector<int>>& grid) { 
        int n = grid.size(); 
        vector<vector<int>> dp(n, vector<int>(n,-1)); 
        int m =1e9; 
       
        for(int j = 0; j < n; j++){ 
            m = min(m ,  f(0, j,grid, -1, n, dp) ); 
        } 
        return m; 
    } 
};