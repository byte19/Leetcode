class Solution(object):
    def sumOfUnique(self, nums):
        sum = 0
        dict = {}
        for num in nums:
            if num not in dict.keys():
                dict[num]=1
            else:
                dict[num]+=1
        for num in nums:
            if dict[num]==1:
                sum+=num
        return sum