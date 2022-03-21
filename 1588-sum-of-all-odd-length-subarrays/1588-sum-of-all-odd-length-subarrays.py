class Solution(object):
    def sumOddLengthSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        
        total = 0
        for i in range(len(arr)):
            sums=0
            count=0
            for j in range(i,len(arr)):
                sums+= arr[j]
                if((count+1)%2==1):
                    total+=sums
                count+=1
        return total