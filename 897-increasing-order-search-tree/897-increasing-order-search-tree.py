# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def inorder(root,lis):
            if root is None:
                return
            
            inorder(root.left,lis)
            lis.append(root.val)
            inorder(root.right,lis)
        
        lis = []
        inorder(root,lis)
        i = 1
        n = len(lis)
        root = TreeNode(lis[0])
        temp = root
        while i<n:
            newNode = TreeNode(lis[i])
            temp.right = newNode
            temp = newNode
            i+=1
        
        return root