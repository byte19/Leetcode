class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        //vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>> prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int ind=N-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int trans=0;trans<2;trans++){
                    long profit = 0;
        
                    if(buy==0){
                        profit = max(-prices[ind] + prev[1][trans] ,prev[0][trans]);
                    }
                    else{
                        profit = max(prices[ind] + prev[0][trans+1] ,prev[1][trans]);
                    }
                    
                    curr[buy][trans] = profit;
                }
            }
            prev = curr;
        }
        return prev[0][0];
    }
};