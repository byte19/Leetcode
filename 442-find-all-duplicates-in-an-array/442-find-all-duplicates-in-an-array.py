class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        c=Counter(nums)
        dup=[item[0] for item in c.items() if item[1]>1]
        return dup