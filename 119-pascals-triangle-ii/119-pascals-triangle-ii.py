class Solution:
    def getRow(self, numRows: int) -> List[int]:
        
        if numRows==0: return [1]
        res = [[1],[1,1]]
        
        for i in range(2,numRows+1):
            lis = []
            temp = res[-1]
            lis.append(temp[0])
            for i in range(1,len(temp)):
                lis.append(temp[i] + temp[i-1])
            lis.append(temp[-1])
            res.append(lis)
        
        return res[-1]
        