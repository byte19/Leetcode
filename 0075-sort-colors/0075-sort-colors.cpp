class Solution {
public:
    void setOnes(vector<int>& nums,int num,int start,int end) {
        for(int i=start;i<end;i++) {
            nums[i] = num;
        }
    }
    void sortColors(vector<int>& nums) {
        int zeroes=0,ones=0,twos=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) zeroes++;
            if(nums[i]==1) ones++;
            if(nums[i]==2) twos++;
        }
        //printf("%d %d %d",zeroes,ones,twos);
        setOnes(nums,0,0,zeroes);
        setOnes(nums,1,zeroes,zeroes+ones);
        setOnes(nums,2,zeroes+ones,zeroes+ones+twos);
    }
};