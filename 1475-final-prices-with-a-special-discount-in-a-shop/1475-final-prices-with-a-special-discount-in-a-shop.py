class Solution(object):
    def finalPrices(self, prices):
        """
        :type prices: List[int]
        :rtype: List[int]
        """
        stack = []
        n = len(prices)
        for i in range(n):
            j = i+1
            ispres = False
            while j<n:
                if prices[j]<=prices[i]:
                    ispres = True
                    stack.append(prices[i] - prices[j])
                    break
                j+=1
            if ispres==False:
                stack.append(prices[i])
        return stack
        