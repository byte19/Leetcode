"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:return
        
        stack = [root]
        outputLis = []
        while stack:
            curr = stack.pop()
            outputLis.append(curr.val)
            for child in reversed(curr.children):
                stack.append(child)
                
        return outputLis