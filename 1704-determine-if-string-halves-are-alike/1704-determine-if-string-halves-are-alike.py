class Solution(object):
    def halvesAreAlike(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dict = {'a':1,'e':2,'i':3,'o':4,'u':5}
        mid = len(s)//2
        half1 = s[:mid]
        half2 = s[mid:]
        n1 = len(half1)
        n2 = len(half2)
        def Count(half,dict,n):
            cnt = 0
            for i in range(n):
                if half[i].lower() in dict.keys():
                    cnt+=1
            return cnt
        
        if Count(half1,dict,n1) == Count(half2,dict,n2):
            return True
        return False