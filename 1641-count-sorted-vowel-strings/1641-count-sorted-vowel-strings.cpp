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
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        return solve(4,vowels,n,dp);
    }
};