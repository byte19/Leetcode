class Solution {
public:
    int solve(int ind,vector<int>& prices,bool bought,int N,vector<vector<int>>& dp){
        if(ind==N) return 0;
        
        
        long profit = 0;
        if(dp[ind][bought]!=-1) return dp[ind][bought];
        if(bought==false){
            int buy = -prices[ind] + solve(ind+1,prices,true,N,dp);
            int notBuy = solve(ind+1,prices,false,N,dp);
            profit = max(buy,notBuy);
        }
        if(bought==true){
            int sell = prices[ind] + solve(ind+1,prices,false,N,dp);
            int notSell = solve(ind+1,prices,true,N,dp);
            profit = max(sell,notSell);
        }
        
        return dp[ind][bought] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N,vector<int>(2,-1));
        return solve(0,prices,false,N,dp);
    }
};