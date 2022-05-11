#User function Template for python3

class Solution:
    def sort012(self,arr,n):
        d = {0:0,1:0,2:0}
        for i in arr:
            d[i]+=1
        
        i = 0
        for key in d:
            for j in range(d[key]):
                arr[i] = key
                i+=1
        return arr
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        ob=Solution()
        ob.sort012(arr,n)
        for i in arr:
            print(i, end=' ')
        print()

# } Driver Code Ends