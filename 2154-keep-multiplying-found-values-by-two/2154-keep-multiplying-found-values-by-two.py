class Solution(object):
    def findFinalValue(self, nums, original):
        """
        :type nums: List[int]
        :type original: int
        :rtype: int
        """
        dict = {}
        for num in nums:
            dict[num] = num
        
        while True:
            if original not in dict.keys():
                return original
            else:
                original*=2