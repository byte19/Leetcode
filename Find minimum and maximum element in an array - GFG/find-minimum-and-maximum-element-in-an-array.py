#User function Template for python3

def getMinMax( a, n):
    mini = a[0]
    maxi = a[0]
    for i in range(1,n):
        if a[i]>maxi:
            maxi = a[i]
        if a[i]<mini:
            mini = a[i]
    
    return [mini,maxi]
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        
        product = getMinMax(a, n)
        print(product[0], end=" ")
        print(product[1])

        T -= 1


if __name__ == "__main__":
    main()



# } Driver Code Ends