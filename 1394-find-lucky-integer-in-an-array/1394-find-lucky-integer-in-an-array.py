class Solution(object):
    def findLucky(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        dict = {}
        for num in arr:
            if num not in dict.keys():
                dict[num]=1
            else:
                dict[num]+=1
        largest = 0
        for num in arr:
            if num==dict[num]:
                if num>largest: largest = num
        if largest:return largest
        return -1