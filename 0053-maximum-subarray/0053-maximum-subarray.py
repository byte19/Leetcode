class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        localSum = 0
        globalSum = -1e9
        for i in range(len(nums)):
            localSum = max(localSum + nums[i],nums[i])
            if localSum > globalSum: globalSum = localSum
        return globalSum