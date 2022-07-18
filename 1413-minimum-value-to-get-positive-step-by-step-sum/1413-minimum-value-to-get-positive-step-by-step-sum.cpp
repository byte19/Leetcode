class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int lowest;
        if(nums[0]>0) lowest=1;
        else lowest = nums[0];
        
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
            lowest = min(lowest,nums[i]);
        }
        if(lowest < 0) return abs(lowest) + 1;
        else return abs(lowest);
        
    }
};