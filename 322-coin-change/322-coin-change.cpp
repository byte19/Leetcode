class Solution {
public:
    int solve(int ind,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int not_take = 0 + solve(ind-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[ind]<=amount) take = 1 + solve(ind,coins,amount-coins[ind],dp);
        
        return dp[ind][amount] = min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1 , 0));
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int am = 0;am<=amount;am++){
                int not_take = 0 + dp[ind-1][am];
                int take = INT_MAX;
                if(coins[ind]<=am) take = 1 + dp[ind][am-coins[ind]];
                
                dp[ind][am] = min(not_take,take);
            }
        }
        if(dp[n-1][amount]>=1e9) return -1;
        return dp[n-1][amount];
        
        
    }
};