class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        
        while len(stones)>1:
            stones.sort()
            
            x = stones.pop()
            y = stones.pop()
            
            if x==y:
                continue
            else:
                stones = [x-y] + stones
        if stones:
            return stones[0]
        return 0