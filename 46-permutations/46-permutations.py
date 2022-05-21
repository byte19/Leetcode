class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        res = []
        
        def permuta(ind,arr):
            if ind>=len(arr):
                lis = []
                for num in arr:
                    lis.append(num)
                res.append(lis)
                return
            
            for i in range(ind,len(arr)):
                arr[ind],arr[i] = arr[i],arr[ind]
                permuta(ind+1,arr)
                arr[ind],arr[i] = arr[i],arr[ind]
            
        
        permuta(0,nums)
        return res