# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements(object):

    def __init__(self, root):
        self.st = set()
        
        def recover(root, val) :
            if(root):
                self.st.add(val)
                recover(root.left, 2 * val + 1)
                recover(root.right, 2 * val + 2)
        
        recover(root, 0)
        

    def find(self, target):
        return target in self.st
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)