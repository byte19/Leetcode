class Solution(object):
    def sortSentence(self, s):
        """
        :type s: str
        :rtype: str
        """
        lis = list(s.split(" "))
        res = [""]*len(lis)
        for word in lis:
            res[int(word[-1])-1] = word[:len(word)-1]
        ans = ""
        for word in res:
            ans = ans +" "+ word
        return ans.lstrip(" ")