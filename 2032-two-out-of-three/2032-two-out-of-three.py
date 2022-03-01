class Solution(object):
    def twoOutOfThree(self, nums1, nums2, nums3):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type nums3: List[int]
        :rtype: List[int]
        """
        dict = {}
        def addtodict(dict,nums):
            for num in nums:
                if num not in dict.keys():
                    dict[num] = 1
                else:
                    dict[num]+=1
        addtodict(dict,set(nums1))
        addtodict(dict,set(nums2))
        addtodict(dict,set(nums3))
        
        lis = []
        
        for key in dict:
            if dict[key]>1:
                lis.append(key)
        return lis