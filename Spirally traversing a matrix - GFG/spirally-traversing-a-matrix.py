#User function Template for python3

class Solution:
    
    #Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self,matrix, r, c):
        lis = []
        rowStart = 0
        rowEnd = r-1
        colStart = 0
        colEnd = c-1
        
        while rowStart<=rowEnd and colStart<=colEnd:
            for i in range(colStart,colEnd+1):
               lis.append(matrix[rowStart][i])
            rowStart+=1
            
            for i in range(rowStart,rowEnd+1):
                lis.append(matrix[i][colEnd])
            colEnd-=1
            
            if rowStart<=rowEnd:
                for i in range(colEnd,colStart-1,-1):
                    lis.append(matrix[rowEnd][i])
            rowEnd-=1
            
            if colStart<=colEnd:
                for i in range(rowEnd,rowStart-1,-1):
                    lis.append(matrix[i][colStart])
            colStart+=1
        
        return lis
               

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r,c = map(int, input().strip().split())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(r):
            row=[]
            for j in range(c):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj = Solution()
        ans = obj.spirallyTraverse(matrix,r,c)
        for i in ans:
            print(i,end=" ")
        print()

# } Driver Code Ends