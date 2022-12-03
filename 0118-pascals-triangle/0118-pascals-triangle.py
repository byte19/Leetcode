class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1]]
        for i in range(1,numRows):
            temp = res[-1]
            lis = []
            lis.append(temp[0])
            for j in range(1,len(temp)):
                lis.append(temp[j] + temp[j-1])
            lis.append(temp[-1])
            res.append(lis)
        return res