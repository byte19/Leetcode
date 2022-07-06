class Solution {
public:
    int solve(int ind,vector<int>& prices,int fee,int buy,int N,vector<vector<int>>& dp){
        if(ind==N) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit = 0;
        if(buy==0) profit = max(-prices[ind] + solve(ind+1,prices,fee,1,N,dp),solve(ind+1,prices,fee,0,N,dp));
        
        else profit = max(prices[ind] - fee + solve(ind+1,prices,fee,0,N,dp),solve(ind+1,prices,fee,1,N,dp));
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        vector<vector<int>> dp(N,vector<int>(2,-1));
        return solve(0,prices,fee,0,N,dp);
    }
};