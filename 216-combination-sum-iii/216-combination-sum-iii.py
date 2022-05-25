class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        dict = {}
        def solve(i,k,n,lis):
            if n<0:
                return
            
            if len(lis)==k and n==0:
                if str(lis) not in dict:
                    b = []
                    b = copy.copy(lis)
                    res.append(b)
                    dict[str(b)] = 1
                    return
            for i in range(i,10):
                lis.append(i)
                solve(i+1,k,n-i,lis)
                lis.pop()
                solve(i+1,k,n,lis)
        
        solve(1,k,n,[])
        return res
        