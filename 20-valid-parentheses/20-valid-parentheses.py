class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        dict = {')':'(',
                ']':'[',
                '}':'{'}
        for c in s:
            if c in ['(','[','{']:
                stack.append(c)
            else:
                if len(stack)>0:
                    if dict[c]==stack[-1]:
                        stack.pop()
                    else:
                        return False
                else:
                    return False
        if len(stack)>0:
            return 0
        return True
        