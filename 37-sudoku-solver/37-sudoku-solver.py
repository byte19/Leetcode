class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        
        def solve(board):
            for i in range(len(board)):
                for j in range(len(board[0])):
                    
                    if board[i][j]=='.':
                        
                        for k in range(1,10):
                            if isValid(board,i,j,k):
                                board[i][j]=str(k)
                            
                                if solve(board)==True:
                                    return True
                                else:
                                    board[i][j]='.'
                        return False
            return True
        
        def isValid(board,row,col,k):
            for i in range(0,9):
                if board[i][col]==str(k):
                    return False
                if board[row][i]==str(k):
                    return False
                if board[3*(row//3) + i//3][3*(col//3) + i%3]==str(k):
                    return False
            return True
        
        solve(board)