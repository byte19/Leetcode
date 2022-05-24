import copy
class Solution(object):
    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        s = s.lower()
        dict = {}
        res = []
        def solve(i,s):
            if i>=len(s):
                b = copy.copy(s)
                if b not in dict:
                    res.append(b)
                    dict[b]=1
                return
            
            s = s[:i] + s[i].upper() + s[i+1:]
            solve(i+1,s)
            s = s[:i] + s[i].lower() + s[i+1:]
            solve(i+1,s)
        
            
        solve(0,s)
        return res