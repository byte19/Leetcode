# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return False
        
        tortoise = head
        hare = head.next
        
        while hare and hare.next:
            if hare == tortoise:
                return True
            
            hare = hare.next.next
            tortoise = tortoise.next
        return False