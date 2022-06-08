class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        minSoFar = prices[0]
        maxProfit = 0
        
        for i in range(1,len(prices)):
            minSoFar = min(minSoFar,prices[i])
            
            maxProfit = max(maxProfit,prices[i]-minSoFar)
        return maxProfit