class Solution:
    def minPartitions(self, n: str) -> int:
        count = 0
        i=0
        while(i<len(n)):
            if int(n[i])>count: count = int(n[i])
            i+=1
        return count
        
        