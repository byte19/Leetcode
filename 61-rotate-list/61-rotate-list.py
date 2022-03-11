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
        
        #find length of the linked list
        temp1 = head
        length = 0
        while temp1:
            length+=1
            temp1 = temp1.next
        
        i=0
        #take mod of the rotation w.r.t length to avoid unnecessary rotation for large k
        mod = k % length
        
        while i<mod:
            temp = head
            prev = temp
            while temp.next: #prev points to 2nd last Node and temp to last Node
                temp = temp.next
                if temp.next:
                    prev = prev.next
            
            #Rotation Logic
            prev.next = None
            temp.next = head
            head = temp
            i+=1
        return head