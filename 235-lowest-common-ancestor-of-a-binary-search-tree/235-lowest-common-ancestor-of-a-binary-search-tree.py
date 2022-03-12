# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p.val > root.val and q.val > root.val and root.right:
            root = root.right
            return self.lowestCommonAncestor(root, p, q)


        if p.val < root.val and q.val < root.val and root.left:
            root = root.left                
            return self.lowestCommonAncestor(root, p, q)

        return TreeNode(root.val)