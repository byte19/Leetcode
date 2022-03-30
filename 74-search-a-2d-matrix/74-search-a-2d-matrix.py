class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        def Bsearch(A):
            p=0
            q=len(A)
            while p<=q:
                m = (p+q)//2
                if A[m]==target:
                    return True
                elif A[m]>target:
                    q=m-1
                else:
                    p=m+1
            return False
            
        for i in range(len(matrix)):
            if matrix[i][0]==target or matrix[i][-1]==target:
                return True
            if matrix[i][0] < target and matrix[i][-1] > target:
                return Bsearch(matrix[i])
        return False