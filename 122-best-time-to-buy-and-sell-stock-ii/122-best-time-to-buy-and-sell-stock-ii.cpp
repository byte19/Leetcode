class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        vector<vector<int>> dp(N+1,vector<int>(2,0));
        vector<long> prev(2,0),curr(2,0);
        
        for(int ind=N-1;ind>=0;ind--){
            for(int bought=0;bought<=1;bought++){
                long profit = 0;
                if(bought){
                    profit = max(-prices[ind] + prev[0],prev[1]);
                }
                else{
                    profit = max(prices[ind] + prev[1],prev[0]);
                }
                
               curr[bought] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};