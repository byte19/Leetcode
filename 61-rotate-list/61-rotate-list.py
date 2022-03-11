# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None:
            return
        if head.next is None:
            return head
        temp1 = head
        length = 0
        while temp1:
            length+=1
            temp1 = temp1.next
        
        i=0
        mod = k % length
        while i<mod:
            temp = head
            prev = temp
            while temp.next:
                temp = temp.next
                if temp.next:
                    prev = prev.next
            prev.next = None
            temp.next = head
            head = temp
            i+=1
        return head