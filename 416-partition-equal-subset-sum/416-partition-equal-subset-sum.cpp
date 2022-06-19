class Solution {
public:
    int sum(vector<int>& arr){
        int res = 0;
        for(auto val:arr){
            res+=val;
        }
        return res;
    }
    
    bool solve(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(target==0) return true;
        if(ind==0) return target==nums[0];
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool not_take = solve(ind-1,nums,target,dp);
        bool take = false;
        if(target >= nums[ind]) take = solve(ind-1,nums,target-nums[ind],dp);
        
        return dp[ind][target] = not_take || take;
    }
    
    bool canPartition(vector<int>& nums) {
        int total = sum(nums);
        int n = nums.size();
        if(total%2 == 0){
            int target = total/2;
            vector<vector<int>> dp(n, vector<int>(target+1,-1));
            return solve(n-1,nums,target,dp);
        }
        return false;
    }
};