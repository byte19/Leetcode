class Solution:
    def totalNQueens(self, n: int) -> int:
        
        res = []
        def solve(col,board,n,leftRow,lowDiag,upDiag):
            
            if col==n:
                li_copy = copy.deepcopy(board)
                res.append(li_copy)
                return
            
            for row in range(n):
                if leftRow[row]==0 and lowDiag[row+col]==0 and upDiag[n-1 + col-row]==0:
                    board[row][col]='Q'
                    leftRow[row]=1
                    lowDiag[row+col]=1
                    upDiag[n-1+col-row]=1
                    solve(col+1,board,n,leftRow,lowDiag,upDiag)
                    leftRow[row]=0
                    lowDiag[row+col]=0
                    upDiag[n-1 + col-row]=0
                    board[row][col]='.'
        
        
        s = ['.']*n
        board = []
        for i in range(n):
            board.append(s)
        leftRow = [0]*n
        lowDiag = [0]*(2*n)
        upDiag = [0]*(2*n)
        solve(0,board,n,leftRow,lowDiag,upDiag)
        return len(res)
        