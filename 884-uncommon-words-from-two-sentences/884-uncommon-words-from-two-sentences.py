class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        words1 = s1.split(" ")
        words2 = s2.split(" ")
        
        dict = {}
        
        for word in words1:
            if word not in dict.keys():
                dict[word] = 1
            else:
                dict[word] += 1
        
        for word in words2:
            if word not in dict.keys():
                dict[word] = 1
            else:
                dict[word] += 1
        lis = []
        for key in dict.keys():
            if dict[key]==1:
                lis.append(key)
        return lis
        