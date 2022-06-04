#User function Template for python3

def Rearrange( a, n):
    # Your code goes here
    x = []
    x[:] = a[::]
    a.clear()
 
    index = 0
    for i in range(len(x)):
        if x[i]<0:
            a.insert(index,x[i])
            index += 1
        else:
            a.append(x[i])
    



#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        Rearrange(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()





    
# } Driver Code Ends