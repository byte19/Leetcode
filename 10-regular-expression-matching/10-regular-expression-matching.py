class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        l1 = len(s)
        l2 = len(p)
        dp = [[0]*(l2+1) for i in range(l1+1)]
        dp[l1][l2] = 1
        l = l2 - 1
        while l >= 0:
            if p[l] == "*":
                dp[l1][l] = dp[l1][l+1]
            
            if l < l2 - 1 and p[l+1] == "*":
                dp[l1][l] = dp[l1][l+1]
            l -= 1

        for i in range(l1-1, -1, -1):
            for j in range(l2-1, -1, -1):
                if p[j] == '*':
                    if p[j-1] == ".":
                        dp[i][j] = dp[i][j+1] or dp[i+1][j]
                    elif p[j-1] == "*":
                        print("Invalid Input") 
                    else:
                        if p[j-1] == s[i]:
                            dp[i][j] = dp[i][j+1] or dp[i+1][j]
                        else:
                            dp[i][j] = dp[i][j+1]
                else:
                    if j < l2 -1:
                        if p[j+1] == "*":
                            dp[i][j] = dp[i][j+1]
                        elif p[j] == s[i] or p[j] == ".":
                            dp[i][j] = dp[i+1][j+1]
                    else:
                        if p[j] == s[i] or p[j] == ".":
                            dp[i][j] = dp[i+1][j+1]

        return dp[0][0]
        