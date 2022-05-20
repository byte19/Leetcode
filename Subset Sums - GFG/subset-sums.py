#User function Template for python3
class Solution:
	def subsetSums(self, arr, N):
	    def SubSum(i,arr,res,summ):
	        
	        if i>=len(arr):
	            res.append(summ)
	            return
	        
	        SubSum(i+1,arr,res,summ+arr[i])
	        SubSum(i+1,arr,res,summ)
	    
	    res = []
	    summ = 0
	    SubSum(0,arr,res,summ)
	    return res

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.subsetSums(arr, N)
        ans.sort()
        for x in ans:
            print(x,end=" ")
        print("")

# } Driver Code Ends