class Solution {
public:
    int solve(int i,vector<char>& vowels,int n,vector<vector<int>>& dp){
        if(i==-1) return 0;
        if(n==0) return 1;
        
        if(dp[i][n]!=-1) return dp[i][n];
        return dp[i][n] = solve(i,vowels,n-1,dp) + solve(i-1,vowels,n,dp);
    }
    int countVowelStrings(int n) {
        vector<char> vowels {'a','e','i','o','u'};
        vector<vector<int>> dp(6,vector<int>(n+1,0));
        //return solve(4,vowels,n,dp);
        
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