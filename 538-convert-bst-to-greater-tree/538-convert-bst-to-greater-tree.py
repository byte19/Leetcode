# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        
        def postorder(root):
            if root is None:
                return 0
            
            postorder(root.right)
            postorder.static_variable += root.val
            root.val = postorder.static_variable
            postorder(root.left)
        
        postorder.static_variable = 0
        postorder(root)
        return root