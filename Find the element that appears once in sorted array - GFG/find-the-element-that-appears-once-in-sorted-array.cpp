//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        //code here.
        int l = 0, h = n-1;
        
        while(l<=h) {
            int mid = (l+h)/2;
            if(a[mid]!=a[mid+1] && a[mid]!=a[mid-1]) return a[mid];
            
            
            if(mid%2!=0) {
                if(a[mid]==a[mid+1]) h = mid-1;
                else l = mid+1;
            }
            else {
                if(a[mid]==a[mid+1]) l = mid+1;
                else h = mid-1;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends