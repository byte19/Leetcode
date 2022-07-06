class Solution {
public:
    int solve(int ind,vector<int>& prices,bool bought,int N,vector<vector<int>>& dp){
        if(ind==N) return 0;
        
        
        
        if(dp[ind][bought]!=-1) return dp[ind][bought];
        long profit = 0;
        
        if(bought==false){
            profit = max(-prices[ind] + solve(ind+1,prices,true,N,dp),solve(ind+1,prices,false,N,dp));
        }
        if(bought==true){
            profit = max(prices[ind] + solve(ind+1,prices,false,N,dp),solve(ind+1,prices,true,N,dp));
        }
        
        return dp[ind][bought] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N+1,vector<int>(2,0));
        //return solve(0,prices,false,N,dp);
        
        for(int ind=N-1;ind>=0;ind--){
            for(int bought=0;bought<=1;bought++){
                long profit = 0;
                if(bought){
                    profit = max(-prices[ind] + dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1],dp[ind+1][0]);
                }
                
               dp[ind][bought] = profit;
            }
        }
        return dp[0][1];
    }
};