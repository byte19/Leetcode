# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        stri = ""
        temp = head
        while temp:
            stri+=str(temp.val)
            temp = temp.next
        if stri == stri[::-1]:
            return True
        return False
        