class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, 0));
        //return solve(n-1,coins,amount,dp);
        
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) dp[0][T] = 1;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int am=0;am<=amount;am++){
                int notTake = dp[ind-1][am];
                int take = 0;
                if(am>=coins[ind]) take = dp[ind][am - coins[ind]];
                
                dp[ind][am] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};