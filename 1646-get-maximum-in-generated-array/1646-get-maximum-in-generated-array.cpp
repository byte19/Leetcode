class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int> nums {0,1};
        for(int i=2;i<=n;i++){
            if(i%2==0) nums.push_back(nums[i/2]);
            else nums.push_back(nums[i/2] + nums[i/2 + 1]);
        }
        int max=0;
        for(int x:nums){
            if(x>max) max = x;
        }
        return max;
    }
};