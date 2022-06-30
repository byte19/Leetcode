class Solution {
public:
    int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = solve(i-1,j-1,s,t,dp);
        else{
            int insert = 1 + solve(i,j-1,s,t,dp);
            int delEte = 1 + solve(i-1,j,s,t,dp);
            int replace = 1 + solve(i-1,j-1,s,t,dp);
            
            return dp[i][j] = min(insert,min(delEte,replace));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return solve(n-1,m-1,word1,word2,dp);
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insert = 1 + dp[i][j-1];
                    int delEte = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    
                    dp[i][j] = min(insert,min(delEte,replace));
                }
            }
        }
        return dp[n][m];
    }
};