class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        numOnes = [0]
        
        for i in range(1,n+1):
            count1 = 0
            while i>0:
                mod = i%2
                if mod==1:
                    count1+=1
                i = i//2
            numOnes.append(count1)
        return numOnes