class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a = len(nums1)
        b = len(nums2)
        nums = []
        for i in range(0,a):
            nums.append(nums1[i])

        for i in range(0,b):
            nums.append(nums2[i])
        
        k = len(nums)
        nums.sort()
        if len(nums)%2!=0:
            return float(nums[k//2])
        return float(((nums[k//2]) + (nums[(k-1)//2]))/2)