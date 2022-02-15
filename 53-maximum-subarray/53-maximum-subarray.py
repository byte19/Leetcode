class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxs = nums[0]
        curr = nums[0]
        for i in range(1,len(nums)):
            curr = max(nums[i],curr+nums[i])
            maxs = max(maxs,curr)

        return maxs
                    
        