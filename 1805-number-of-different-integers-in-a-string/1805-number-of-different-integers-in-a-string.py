class Solution(object):
    def numDifferentIntegers(self, word):
        """
        :type word: str
        :rtype: int
        """
        ll = [str(i) for i in range(10)]
        
        mast = []
        temp = ""
        for i in range(len(word)):
            if word[i] in ll:
                temp+=word[i]
            else:
                if temp:
                    mast.append(int(temp))
                temp = ""
                
            if i == len(word)-1 and temp:
                mast.append(int(temp))
        return len(set(mast))