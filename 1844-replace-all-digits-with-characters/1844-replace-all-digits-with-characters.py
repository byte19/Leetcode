class Solution(object):
    def replaceDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        for i in range(len(s)):
            if i%2==0:
                res+=s[i]
            else:
                res += chr(ord(s[i-1])+int(s[i]))
        return res
        