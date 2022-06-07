class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if len(nums)==1: return nums
        c0 = 0
        c1 = 0
        c2 = 0
        
        for i in range(len(nums)):
            if nums[i] == 0:
                c0+=1
            elif nums[i] == 1:
                c1+=1
            else:
                c2+=1
        
        i=0
        while i<c0:
            nums[i]=0
            i+=1
        
        j=i
        lim = j+c1
        while j < lim:
            nums[j]=1
            j+=1
        k=j
        lim = k+c2
        while k < lim:
            nums[k]=2
            k+=1
        
        return nums