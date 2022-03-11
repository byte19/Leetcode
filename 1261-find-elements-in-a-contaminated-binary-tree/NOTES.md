"""
​
def __init__(self, root):
self.root = root
self.root.val = 0
self.dict = {}
def find(self, target):
if target in self.dict:
return True
else:
stack = [self.root]
while stack:
curr = stack.pop()
self.dict[curr.val] = curr.val
if curr.val==target:
return True
if curr.left:
curr.left.val = 2*curr.val + 1
stack.append(curr.left)
if curr.right:
curr.right.val = 2*curr.val + 2
stack.append(curr.right)
return False
"""