class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)-1
        if n==0: return nums[n]
        dp = [-1]*(n+1)
        def solve(ind,dp):
            if ind==0: return nums[ind]
            if ind<0: return 0
            
            if dp[ind]!=-1: return dp[ind]
            
            pick = nums[ind] + solve(ind-2,dp)
            not_pick = solve(ind-1,dp)
        
            dp[ind] = max(pick,not_pick)
            return dp[ind]
        
        solve(n,dp)
        return dp[n]