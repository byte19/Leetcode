class CombinationIterator(object):

    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.res = []
        self.ind = 0
        self.chars = characters
        self.cl = combinationLength
        
        
        def solve(i,chars,cl,temp):
            if len(temp) == cl:
                b = copy.copy(temp)
                self.res.append(temp)
                return
            
            for j in range(i,len(chars)):
                solve(j+1,chars,cl,temp + chars[j])
        
        solve(0,self.chars,self.cl,"")
        
    def next(self):
        """
        :rtype: str
        """
        temp = self.res[self.ind]
        self.ind+=1
        return temp
        
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.ind < len(self.res):
            return True
        return False


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()