class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1: return nums[0]
        def solve(nums):
            dp = [0]*len(nums)
            dp[0] = nums[0]
            for i in range(1,len(nums)):
                take = nums[i]
                if i>1: take+=dp[i-2]
                
                not_take = dp[i-1]
                
                dp[i] = max(take,not_take)
            
            return dp[-1]
        
        ans1 = solve(nums[:len(nums)-1])
        ans2 = solve(nums[1:])
        
        return max(ans1,ans2)