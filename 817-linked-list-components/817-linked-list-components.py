# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: ListNode
        :type nums: List[int]
        :rtype: int
        """
        consec = False
        connected = 0
        while head:
            contains_both = head.val in nums
            if not consec and contains_both:
                connected += 1
                consec = True
            elif not contains_both:
                consec = False
            head = head.next
        return connected
        