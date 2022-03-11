class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if s=="":return t
        
        dict = {}
        for c in s:
            if c in dict:
                dict[c]+=1
            else:
                dict[c]=1
        
        for c in t:
            if c in dict and dict[c]>0:
                dict[c]-=1
            else:
                return c
            
        