class Solution {
public:
    int solve(int ind,vector<int>& nums,int n,int lastInd,vector<vector<int>>& dp){
        if(ind==n) return 0;
        
        if(dp[ind][lastInd+1]!=-1) return dp[ind][lastInd+1];
        int len = solve(ind+1,nums,n,lastInd,dp);
        if(lastInd==-1 || nums[ind]>nums[lastInd]) len = max(1+solve(ind+1,nums,n,ind,dp),len);
        
        return dp[ind][lastInd+1] = len;
        //else return solve(ind+1,nums,n,lastInd);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,nums,n,-1,dp);
        
    }
};