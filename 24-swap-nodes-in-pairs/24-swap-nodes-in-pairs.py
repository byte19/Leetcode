# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        if head==None or head.next == None:
            return head
        cur = head
        nex = head.next
        # swap values and move pointer to cur.next.next
        while cur and nex:
            cur.val, nex.val = nex.val, cur.val
            cur = nex.next
            if cur!=None:
                nex = cur.next
            else:
                break
        return head