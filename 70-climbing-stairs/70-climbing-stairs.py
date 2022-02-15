class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==0:return 0
        if n==1:return 1
        if n==2:return 2
        steps = [0,1,2]
        for i in range(3,n+1):
            steps.append(steps[-1] + steps[-2])
        return steps[-1]
            
        