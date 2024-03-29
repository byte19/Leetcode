//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int rem = X - A[i] - A[j];
                int l=j+1,h=n-1;
                while(l<=h) {
                    int mid = (l+h)>>1;
                    
                    if(A[mid]==rem) return true;
                    
                    else if(A[mid] > rem) h = mid-1;
                    
                    else l = mid+1;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends