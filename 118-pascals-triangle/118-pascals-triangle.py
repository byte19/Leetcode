class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        if numRows==1: return [[1]]
        
        res = [[1],[1,1]]
        
        for i in range(2,numRows):
            lis = []
            temp = res[-1]
            lis.append(temp[0])
            for i in range(1,len(temp)):
                lis.append(temp[i] + temp[i-1])
            lis.append(temp[-1])
            res.append(lis)
        
        return res