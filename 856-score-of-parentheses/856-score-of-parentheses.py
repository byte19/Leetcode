class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stk = [[0,0]]
        for v in s:
            p = stk[-1]
            if v=='(':
                stk.append([v,0])
            else:
                if not p[1]:
                    p[1] = 1
                if stk[-2][0]=='(':
                    stk[-2][1] += 2*p[1]
                else:
                    stk[-2][1] += p[1]
                stk.pop()
                    
                    
        return stk[0][1]