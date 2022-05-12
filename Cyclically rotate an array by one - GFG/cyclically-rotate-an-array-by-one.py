#User function Template for python3

def rotate( arr, n):
    if n==1:
        return arr
    rotated = False
    i = 1
    key = arr[0]
    while True:
        temp = arr[i]
        arr[i] = key
        key = temp
        i = (i+1)%n
        if i==1:
            return arr
        


#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()





    
# } Driver Code Ends