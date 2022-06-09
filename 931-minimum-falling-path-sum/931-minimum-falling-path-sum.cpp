class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        for(int j=0;j<n;j++) dp[n-1][j] = matrix[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ld=1e9,rd=1e9,d=1e9;
                if(j-1>=0) ld = matrix[i][j] + dp[i+1][j-1];
                d = matrix[i][j] + dp[i+1][j];
                if(j+1<n) rd = matrix[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(ld,min(d,rd));
            }
        }
        int mini = 1e9;
        
        for(int i=0;i<n;i++){
            if(dp[0][i]<mini) mini = dp[0][i];
        }
        
        return mini;
    }
};