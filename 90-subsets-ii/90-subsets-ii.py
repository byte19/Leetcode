class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        def subsets(i,arr,res,lis):
            if i>=len(arr):
                li_copy = []
                li_copy.extend(sorted(lis))
                res.append(li_copy)
                return
            
            lis.append(arr[i])
            subsets(i+1,arr,res,lis)
            lis.pop()
            
            subsets(i+1,arr,res,lis)
        
        res = []
        lis = []
        subsets(0,nums,res,lis)
        
        b_set = set(map(tuple,res))
        b = map(list,b_set)
        
        return b
            
            
            
            
            