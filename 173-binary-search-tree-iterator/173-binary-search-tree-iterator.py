class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator(object):

    def inorder(self, root, result):
        if not root:
            return
        self.inorder(root.left, result)
        result.append(root.val)
        self.inorder(root.right, result)

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        result = []
        curr = root
        self.inorder(curr, result)
        self.result = result

    def next(self):
        """
        :rtype: int
        """
        if self.result:
            val = self.result.pop(0)
            return val
        else:
            return None

    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.result) > 0