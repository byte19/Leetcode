#include<bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int localSum = 0;
        int globalSum = -1e9;
        for(int i=0;i<nums.size();i++) {
            localSum = max(localSum + nums[i],nums[i]);
            if(localSum > globalSum) globalSum = localSum;
        }
        return globalSum;
    }
};