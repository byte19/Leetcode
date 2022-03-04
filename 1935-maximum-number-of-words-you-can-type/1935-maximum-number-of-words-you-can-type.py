class Solution(object):
    def canBeTypedWords(self, text, brokenLetters):
        """
        :type text: str
        :type brokenLetters: str
        :rtype: int
        """
        words = text.split(" ")
        dict = {}
        broken = False
        valid = 0
        for ch in brokenLetters:
            dict[ch]=ch
        for word in words:
            i=0
            broken = False
            while i < len(word):
                if word[i] in dict.keys():
                    broken = True
                    break
                i+=1
            if broken==False:
                valid+=1
        return valid
            