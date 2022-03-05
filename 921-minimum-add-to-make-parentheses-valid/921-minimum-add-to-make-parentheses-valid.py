class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """
        i=0
        stack = []
        while i<len(s):
            if s[i]=='(':
                stack.append(s[i])
            else:
                if len(stack)>0:
                    if stack[-1]=='(':
                        stack.pop()
                    else:
                        stack.append(s[i])
                else:
                    stack.append(s[i])
            i+=1
        return len(stack)