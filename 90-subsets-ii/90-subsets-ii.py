class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        
        def subSets(ind,arr,lis):
            l_copy = []
            l_copy.extend(lis)
            res.append(l_copy)
            
            for i in range(ind,len(arr)):
                if i!=ind and arr[i]==arr[i-1]:continue
                
                lis.append(arr[i])
                subSets(i+1,arr,lis)
                lis.pop()
        
        nums.sort()    
        subSets(0,nums,[])
        return res
            
            
            
            