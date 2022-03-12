class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        def fact(m):
            mul = 1
            while m>0:
                mul *= m
                m-=1
            return mul
        factm = fact(m-1)
        factn = fact(n-1)
        
        num = fact(m-1 + n-1)
        den = factm*factn
        
        return num//den