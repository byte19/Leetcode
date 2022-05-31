class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        
        if rowIndex==0: return [1]
        res = [1,1]
        
        for i in range(2,rowIndex+1):
            
            lis = []
            lis.append(res[0])
            
            for i in range(1,len(res)):
                lis.append(res[i] + res[i-1])
            lis.append(res[-1])
            
            res = lis
        
        return res
        