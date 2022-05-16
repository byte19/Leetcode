class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        ind1 = 0
        ind2 = 0
        i1 = False
        i2 = False
        for i in range(len(nums)-2,-1,-1):
            if nums[i]<nums[i+1]:
                ind1 = i
                i1 = True
                break
        for i in range(len(nums)-1,-1,-1):
            if nums[i] > nums[ind1]:
                ind2 = i
                i2 = True
                break
        if i1 and i2:
            nums[ind1],nums[ind2] = nums[ind2],nums[ind1]
            i = ind1+1
        else:
            i = ind1
        j = len(nums)-1
        while i<=j:
            nums[i],nums[j] = nums[j],nums[i]
            i+=1
            j-=1
        
        return nums
        