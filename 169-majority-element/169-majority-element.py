class Solution(object):
    def majorityElement(self, nums):
        dict = {}
        n = len(nums)
        for num in nums:
            if num not in dict.keys():
                dict[num]=1
            else:
                dict[num] += 1
        maj = 0
        s = set(nums)
        for num in s:
            if dict[num] > n//2:
                return num
        