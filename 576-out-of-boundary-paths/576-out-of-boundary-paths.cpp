class Solution {
public:
    long long solve(int row,int col,int maxMove,int m,int n,vector<vector<vector<long long>>>& dp){
        if(row<0 || row>=m || col<0 || col>=n) return 1;
        if(maxMove==0) return 0;
        
        if(dp[row][col][maxMove]!=-1) return dp[row][col][maxMove];
        int mod = 1e9+7;
        long long left = solve(row,col-1,maxMove-1,m,n,dp);
        long long right = solve(row,col+1,maxMove-1,m,n,dp);
        long long up =  solve(row-1,col,maxMove-1,m,n,dp);
        long long down = solve(row+1,col,maxMove-1,m,n,dp);
        
        return dp[row][col][maxMove] = (left%mod + right%mod + up%mod + down%mod)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int mod = 1e9+7;
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,m,n,dp) % mod;
    }
};