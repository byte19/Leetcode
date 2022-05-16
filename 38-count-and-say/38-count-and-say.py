class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1:return "1"
        if n==2:return "11"
        
        s ="11"
        for i in range(3,n+1):
            res = ""
            c=1
            s += "&"
            for j in range(1,len(s)):
                if s[j]==s[j-1]:
                    c+=1
                else:
                    res+=str(c)+s[j-1]
                    c=1
            s = res
        return res