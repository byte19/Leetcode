#include<bits/stdc++.h>
class Solution {
public:
    int binary_search(vector<int>& nums,int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            
            if(target > nums[mid]) low = mid+1;
            if(target < nums[mid]) high = mid-1;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n; i++)
        {
            int j=i+1,k=n-1;//two pointers
            while(j<n && j<k)
            {
                if(nums[j]+nums[k] == -nums[i])
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k!=0 && nums[k]==nums[k-1]) k--;//to avoid duplicates 
                    while(j!=n-1 && nums[j]==nums[j+1]) j++;
                    j++,k--;
                }
                else if(nums[j]+nums[k] > -nums[i]) 
                {
                    while(k!=0 && nums[k]==nums[k-1]) k--;
                    k--;
                }
                else
                {
                    while(j!=n-1 && nums[j]==nums[j+1]) j++;
                    j++;
                }
            }
            while(i!=n-1 && nums[i]==nums[i+1]) i++;
        }
        for(auto triplet : ans)
            sort(triplet.begin(),triplet.end());
        return ans;
}
};