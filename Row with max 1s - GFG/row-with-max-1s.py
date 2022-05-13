#User function Template for python3
class Solution:
	def rowWithMax1s(self,arr, n, m):
	    resIn = -1
	    rowIn = 0
	    colIn = m-1
	    while colIn>=0 and rowIn<n:
	        
	        if arr[rowIn][colIn]==0:
	            rowIn+=1
	        elif arr[rowIn][colIn]==1:
	            
	            resIn = rowIn
	            colIn-=1
	           
	    return resIn

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]
        
        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr, n, m)
        print(ans)
        tc -= 1

# } Driver Code Ends