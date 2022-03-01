class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def check(s,t):
            dict = {}
            for i in range(len(s)):
                if s[i] not in dict.keys():
                    dict[s[i]] = t[i]
                
                elif dict[s[i]] != t[i]:
                    return False
            return True
        if check(s,t)==False or check(t,s)==False:
            return False
        return True
        