class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        total=0
        ans=0
        for i in s:
            if i=='L':
                total+=1
            else:
                total-=1
            if total==0:
                ans+=1
        return ans