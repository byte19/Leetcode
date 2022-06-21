class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, 0));
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int T=0;T<=amount;T++){
            if(T%coins[0]==0) prev[T] = 1;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int am=0;am<=amount;am++){
                int notTake = prev[am];
                int take = 0;
                if(am>=coins[ind]) take = curr[am - coins[ind]];
                
                curr[am] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};