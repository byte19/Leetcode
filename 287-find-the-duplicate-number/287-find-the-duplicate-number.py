class Solution(object):
    def findDuplicate(self, nums):
        dict = {}
        for num in nums:
            if dict.get(num):
                return num
            else:
                dict[num] = num