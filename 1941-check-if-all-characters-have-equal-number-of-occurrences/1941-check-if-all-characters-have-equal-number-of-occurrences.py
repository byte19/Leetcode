class Solution(object):
    def areOccurrencesEqual(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dict = {}
        i = 0
        n = len(s)
        while i<n:
            if s[i] not in dict.keys():
                dict[s[i]] = 1
            else:
                dict[s[i]] += 1
            i+=1
        
        j = 1
        while j<n:
            if dict[s[j]] != dict[s[j-1]]:
                return False
            j+=1
        return True
        