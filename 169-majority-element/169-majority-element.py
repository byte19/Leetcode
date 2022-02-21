class Solution(object):
    def majorityElement(self, nums):
        x = set(nums)
        for num in x:
            if nums.count(num)>(len(nums)//2):
                return num
        
        