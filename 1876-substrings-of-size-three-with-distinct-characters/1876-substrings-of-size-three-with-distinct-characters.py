class Solution(object):
    def countGoodSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        return sum([len(set(s[i:i+3]))==len(s[i:i+3]) for i in range(len(s)-2)])