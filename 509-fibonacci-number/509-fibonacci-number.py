class Solution(object):
    def fib(self, n):
        if n==0:
            return 0
        if n==1:
            return 1
        fib = [0,1]
        for i in range(2,n):
            fib.append(fib[-1] + fib[-2])
        return fib[-1] + fib[-2]