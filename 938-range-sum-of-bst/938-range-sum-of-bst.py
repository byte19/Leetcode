# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: int
        """
        def inorder(root,lis):
            if root is None:
                return
            
            inorder(root.left,lis)
            lis.append(root.val)
            inorder(root.right,lis)
    
        lis = []
        inorder(root,lis)
        res = 0
        for i in range(len(lis)):
            if lis[i]>=low and lis[i]<=high:
                res+=lis[i]
        return res
        