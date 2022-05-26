class Solution(object):
    def circularPermutation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: List[int]
        """
        res = [i ^ (i // 2) for i in range(pow(2, n))]   #store gray code
        for i in range(len(res)):            
            if start == res[i]:             #match with start value
                return res[i:]+res[:i]