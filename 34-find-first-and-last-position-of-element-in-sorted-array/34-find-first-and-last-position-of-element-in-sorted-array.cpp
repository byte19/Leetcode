#include<bits/stdc++.h>
class Solution {
public:
    int binarySearch(vector<int>& nums,int n,int target) {
        int p=0,q=n-1;
        while(p<=q) {
            int mid = (p+q)/2;
            
            if(nums[mid]==target) return mid;
            if(nums[mid] > target) q = mid-1;
            if(nums[mid] < target) p = mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int ind = binarySearch(nums,nums.size(),target);
        if(ind==-1) return {-1,-1};
        else {
            vector<int> res {ind,ind};
            int start = ind,end = ind;
            while(1) {
                bool stopped = true;
                if(start>=0 && nums[start]==target) {
                    res[0]=start;
                    start-=1;
                    stopped=false;
                }
                if(end < nums.size() && nums[end]==target) {
                    res[1]=end;
                    end+=1;
                    stopped=false;
                }
                if(stopped) return res;
            }
        }
    }
};