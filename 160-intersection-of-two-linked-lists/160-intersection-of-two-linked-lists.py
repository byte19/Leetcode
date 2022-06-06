# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        temp1, temp2 = headA, headB
        l1, l2 = 0, 0
        
        while temp1.next:
            temp1 = temp1.next
            l1 += 1
        
        while temp2.next:
            temp2 = temp2.next
            l2 += 1
        
        if temp1 != temp2:
            return None
        
        diff = abs(l1-l2)
        if l1 > l2:
            for i in range(diff):
                headA = headA.next
        else:
            for i in range(diff):
                headB = headB.next
        
        while headA:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
        