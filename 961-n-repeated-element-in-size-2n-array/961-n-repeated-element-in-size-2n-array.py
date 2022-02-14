class Solution(object):
    def repeatedNTimes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)//2
        dict = {}
        for num in nums:
            if num not in dict.keys():
                dict[num]=1
            else:
                dict[num]+=1
        for num in nums:
            if dict[num]==n:
                return num
        