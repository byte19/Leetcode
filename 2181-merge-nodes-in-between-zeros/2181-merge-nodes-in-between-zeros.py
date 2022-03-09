# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        temp = head
        while temp and temp.next:
            sum = 0
            curr = temp.next
            while curr.val != 0:
                sum+=curr.val
                curr = curr.next
            
            temp.val= sum
            temp.next = curr
            temp = curr
        
        temp = head
        while temp.next.val != 0:
            temp = temp.next
        temp.next = None
        return head