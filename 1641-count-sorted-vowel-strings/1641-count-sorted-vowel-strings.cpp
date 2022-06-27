class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,0));
        
        for(int i=0;i<5;i++) dp[i][0] = 1;
        
        for(int i=0;i<5;i++){
            for(int j=1;j<=n;j++){
                int pick = dp[i][j-1];
                int notPick = 0;
                if(i>0) notPick = dp[i-1][j];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[4][n];
    }
};