class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        Cstring = 0
        dict = {}
        i=0
        while i<len(allowed):
            dict[allowed[i]] = ord(allowed[i])
            i+=1
        
        for word in words:
            i = 0
            pres = True
            while i<len(word):
                if word[i] not in dict.keys():
                    pres = False
                i+=1
            if pres==True:
                Cstring+=1
        return Cstring
            