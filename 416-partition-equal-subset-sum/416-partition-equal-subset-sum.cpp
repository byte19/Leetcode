class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) total+=nums[i];
        if(total%2 == 0 && n>1){
            int target = total/2;
            vector<vector<bool>> dp(n, vector<bool>(target+1,0));
            for(int i=0;i<n;i++) dp[i][0] = true;
            if(target>=nums[0]) dp[0][nums[0]] = true;
            
            for(int ind=1;ind<n;ind++){
                for(int k=1;k<=target;k++){
                    bool not_take = dp[ind-1][k];
                    bool take = false;
                    if(k >= nums[ind]) take = dp[ind-1][k-nums[ind]];
                    
                    dp[ind][k] = take || not_take;
                }
            }
            return dp[n-1][target];
        }
        return false;
    }
};