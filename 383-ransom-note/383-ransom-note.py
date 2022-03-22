class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        magdict = {}
        for c in magazine:
            if c in magdict:
                magdict[c]+=1
            else:
                magdict[c] = 1
        for i in range(len(ransomNote)):
            if ransomNote[i] in magdict:
                if magdict[ransomNote[i]]==0:
                    return False
                else:
                    magdict[ransomNote[i]]-=1
            else:
                return False
        return True
                