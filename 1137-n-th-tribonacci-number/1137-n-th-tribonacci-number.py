class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0: return 0
        if n==1: return 1
        if n==2: return 1
        lis = [0,1,1]
        for i in range(3,n):
            lis.append(lis[-1] + lis[-2] + lis[-3])
        return lis[-1] + lis[-2] + lis[-3]