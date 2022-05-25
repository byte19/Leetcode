import copy
class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        
        res = []
        
        def solve(arr,temp,n):
            if len(temp)==n:
                b = copy.copy(temp)
                res.append(b)
                return
            
            for j in range(3):
                if temp!="" and temp[-1]==arr[j]: continue
                solve(arr,temp+arr[j],n)
        solve(['a','b','c'],"",n)
        
        if k>len(res): return ""
        return res[k-1]