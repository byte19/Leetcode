class Solution(object):
    def interpret(self, command):
        """
        :type command: str
        :rtype: str
        """
        res = ""
        i = 0
        while i<len(command):
            if command[i]!='(' and command[i]!=')':
                res+=command[i]
            if command[i]=='(':
                if command[i+1]==')':
                    res+='o'
            i+=1
        return res
        