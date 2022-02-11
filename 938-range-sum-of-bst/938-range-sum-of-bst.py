# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rangeSumBST(self, root, low, high):
        su = []
        def inorder(root,low,high,su):
            if root==None:
                return
            
            inorder(root.left,low,high,su)
            
            if root.val in range(low,high+1):
                su.append(root.val)
            
            inorder(root.right,low,high,su)
        
        inorder(root,low,high,su)
        x = 0    
        for num in su:
            if num>=low and num<=high:
                x+=num
        return x
        
                