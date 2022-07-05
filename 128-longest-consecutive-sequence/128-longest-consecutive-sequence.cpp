class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = -1e9,temp = 1;
        int i=1,n=nums.size();
        if(n==0) return 0;
        
        while(i<n){
            if(nums[i]-1 == nums[i-1]) temp++,i++;
            else if(nums[i]==nums[i-1]) i++;
            else maxi = max(maxi,temp),temp=1,i++;
        }
        maxi = max(maxi,temp);
        return maxi;
    }
};