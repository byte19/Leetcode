class Solution(object):
    def countPoints(self, rings):
        """
        :type rings: str
        :rtype: int
        """
        dict = {}
        for i in range(10):
            dict[i] = []
        
        res = 0
        i=0
        while i<len(rings):
            j = i
            dict[int(rings[j+1])].append(rings[j])
            i+=2
        
        lis = ['B','G','R']
        
        for i in range(10):
            lis1 = dict[i]
            if 'R' in lis1 and 'B' in lis1 and 'G' in lis1:
                res+=1
        return res