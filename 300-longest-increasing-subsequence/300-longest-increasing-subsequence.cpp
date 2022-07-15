class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            
            for(int lastInd=ind-1;lastInd>=-1;lastInd--){
                
                int len = dp[ind+1][lastInd+1];
                if(lastInd==-1 || nums[ind]>nums[lastInd]) len = max(1+dp[ind+1][ind+1],len);
                
                dp[ind][lastInd+1] = len;
            }
        }
        return dp[0][0];
        
    }
};