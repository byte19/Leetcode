class CustomStack(object):

    def __init__(self, maxSize):
        """
        :type maxSize: int
        """
        self.maxSize = maxSize
        self.stack = []
        self.i = 0

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if self.i < self.maxSize:
            self.stack.append(x)
            self.i += 1
        

    def pop(self):
        """
        :rtype: int
        """
        if self.i==0:
            return -1
        self.i -= 1
        return self.stack.pop()
        

    def increment(self, k, val):
        """
        :type k: int
        :type val: int
        :rtype: None
        """
        for j in range(k):
            if self.i <= j:
                break
            self.stack[j] += val
        return self.stack
        
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)