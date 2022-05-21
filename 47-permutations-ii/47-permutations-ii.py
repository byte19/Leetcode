class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        freq = [0]*n
        res = []
        
        def recurPermute(lis,freq,arr):
            if len(lis)==len(arr):
                li_copy = []
                li_copy.extend(lis)
                res.append(li_copy)
                return
            
            for i in range(len(arr)):
                if freq[i]==0:
                    lis.append(arr[i])
                    freq[i]=1
                    recurPermute(lis,freq,arr)
                    freq[i]=0
                    lis.pop()
        
        recurPermute([],freq,nums)
        
        b_set = set(map(tuple,res))
        b = map(list,b_set)
        
        return b