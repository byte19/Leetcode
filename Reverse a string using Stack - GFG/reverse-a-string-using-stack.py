#{ 
#Driver Code Starts

 # } Driver Code Ends
def reverse(S):
    stack = []
    for c in S:
        stack.append(c)
    res = ""
    while stack:
        res+=stack.pop()
    return res

#{ 
#Driver Code Starts.
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        str1=input()
        print(reverse(str1))
#} Driver Code Ends