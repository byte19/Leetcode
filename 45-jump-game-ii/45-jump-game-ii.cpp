class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[n-1]=0;
        for(int ind=n-2;ind>=0;ind--){
            int temp = 1e9;
            for(int i=1;i<=nums[ind];i++){
                if(ind+i < n) temp = min(temp,1+dp[ind+i]);
            }
            dp[ind] = temp;
        }
        return dp[0];
    }
};