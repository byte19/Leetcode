import itertools
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        def subsets(i,arr,lis):
            if i>=len(arr):
                l_copy = []
                l_copy.extend(lis)
                res.append(l_copy)
                return
            
            lis.append(arr[i])
            subsets(i+1,arr,lis)
            lis.pop()
            
            subsets(i+1,arr,lis)
        
        subsets(0,nums,[])
        return res