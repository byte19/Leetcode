//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
        int ans = 0;
        for(int i=0;i<n;i++) {
            int rs = 0;
            for(int j=i+1;j<n;j++) { //RS
                if(A[j] < A[i]) {
                    rs = A[j];
                    break;
                }
            }
            
            int ls = 0;
            for(int j=i-1;j>=0;j--) { //ls
                if(A[j] < A[i]) {
                    ls = A[j];
                    break;
                }
            }
            
            ans = max(ans,abs(ls-rs));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends