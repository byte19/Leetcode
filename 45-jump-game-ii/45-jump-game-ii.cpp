class Solution {
public:
    int solve(int ind,vector<int>& nums,int n,vector<int>& dp){
        if(ind==n) return 0;
        if(ind>n) return 1e9;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int temp = 1e9;
        for(int i=1;i<=nums[ind];i++){
            temp = min(temp,1+solve(ind+i,nums,n,dp));
        }
        return dp[ind] = temp;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,n-1,dp);
    }
};