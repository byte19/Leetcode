class Solution(object):
    def singleNumber(self, nums):
        dict = {}
        for num in nums:
            if num not in dict.keys():
                dict[num]=1
            else:
                dict[num]+=1
        
        for num in nums:
            if dict[num]==1:
                return num
        