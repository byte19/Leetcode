#User function Template for python3

def reverseWord(s):
    
    j=len(s)-1
    new_s = ""
    while j>=0:
        new_s += s[j]
        j-=1
    return new_s
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while(t>0):
        s = input()
        print(reverseWord(s))
        t = t-1

# } Driver Code Ends