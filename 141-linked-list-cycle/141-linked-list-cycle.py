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
        loop = False
        dict = {}
        temp = head
        while temp:
            if temp in dict:
                loop = True
                break
            else:
                dict[temp] = temp
            temp = temp.next
        if loop:
            return True
        return False
        