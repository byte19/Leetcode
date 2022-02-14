class Solution(object):
    def distributeCandies(self, candyType):
        """
        :type candyType: List[int]
        :rtype: int
        """
        n = len(candyType)
        sett = set(candyType)
        c,i=0,0
        if len(sett)<=n//2:
            return len(sett)
        while i<n//2:
            c+=1
            i+=1
        return c
        