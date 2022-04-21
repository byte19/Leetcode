class MyHashSet(object):

    def __init__(self):
        self.dict = {}

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        self.dict[key] = key
        

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        if key in self.dict:
            del self.dict[key]        

    def contains(self, key):
        """
        :type key: int
        :rtype: bool
        """
        if key in self.dict:
            return True
        return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)