class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        
        
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                if nums[i] + nums[j] == target:
                    return [i,j]
        """
        hashmap = {}
        for i in range(len(nums)):
            j =  target-nums[i]
            if(j in hashmap):
                return [hashmap[j],i]
            hashmap[nums[i]] = i
        
            
                