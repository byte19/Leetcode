class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l,r=0,len(s)-1
        while l<r:
            if s[l]==s[r]:
                l+=1
                r-=1
            else:
                return s[:l]+s[l+1:]==(s[:l]+s[l+1:])[::-1] or s[:r]+s[r+1:]==(s[:r]+s[r+1:])[::-1] #removing element at l or r and checking for palindrom
        return True