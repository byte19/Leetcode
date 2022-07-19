class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int hash[n];
        for(int i=0;i<n;i++) hash[i]=i;
        
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1) dp[i]=dp[j]+1,hash[i]=j;
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++) res = max(res,dp[i]);
        return res;
    }
};