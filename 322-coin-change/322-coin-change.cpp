class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        //vector<vector<int>> dp(n, vector<int>(amount+1 , 0));
        
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) prev[T] = T/coins[0];
            else prev[T] = 1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int am = 0; am<=amount ; am++){
                
                int not_take = 0 + prev[am];
                int take = INT_MAX;
                if(coins[ind]<=am) take = 1 + curr[am-coins[ind]];
                
                curr[am] = min(not_take,take);
            }
            prev = curr;
        }
        if(prev[amount]>=1e9) return -1;
        return prev[amount];
        
        
    }
};