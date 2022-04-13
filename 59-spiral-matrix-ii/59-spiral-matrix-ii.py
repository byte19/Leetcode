class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        mat = []
        colStart = 0
        colEnd = n-1
        rowStart = 0
        rowEnd = n-1
        count = 1
        for i in range(n):
            lis = []
            for i in range(n):
                lis.append(0)
            mat.append(lis)
            
            
        while colStart<=colEnd and rowStart<=rowEnd:
            for i in range(colStart,colEnd+1):
                mat[rowStart][i] = count
                count+=1
            rowStart+=1
            
            for i in range(rowStart,rowEnd+1):
                mat[i][colEnd] = count
                count+=1
            colEnd-=1
            
            if colStart<=colEnd:
            
                for i in range(colEnd,colStart-1,-1):
                    mat[rowEnd][i] = count
                    count+=1
                rowEnd-=1
            if rowStart<=rowEnd:
                for i in range(rowEnd,rowStart-1,-1):
                    mat[i][colStart] = count
                    count+=1
                colStart+=1
        return mat
    