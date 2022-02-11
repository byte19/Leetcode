class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        k = [i for i in range(0,len(nums)+1)]
        for ele in k:
            if ele not in nums:
                return ele
    
            