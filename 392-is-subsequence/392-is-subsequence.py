class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        j=0
        i=0
        n = len(t)
        m = len(s)
        while i<n and j<m:
            if s[j] == t[i]:
                j+=1
            i+=1
        if j==m:
            return True
        return False