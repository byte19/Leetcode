class Solution {
public:
    
    int f(int row,int col,vector<vector<int>>& matrix,int n,vector<vector<int>>& dp){
        if(col>=n || col<0) return 1e9;
        if(row==n-1) return matrix[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        
        int ld = matrix[row][col] + f(row+1,col-1,matrix,n,dp);
        int d = matrix[row][col] + f(row+1,col,matrix,n,dp);
        int rd = matrix[row][col] + f(row+1,col+1,matrix,n,dp);
        
        return dp[row][col] = min(d,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        for(int col=0;col<n;col++){
            int m = f(0,col,matrix,n,dp);
            if(res > m) res = m;
        }
        return res;
    }
};