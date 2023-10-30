//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

using ll = long long int;
using pp = pair<int,int>;
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
        ll ans = 0;
        for(int i=0;i<32;i++) {
            ll cntOne = 0, cntZer = 0;
            for(int i=0;i<n;i++) {
                int mod = arr[i]%2;
                arr[i]/=2;
                
                cntOne+= (mod==1)?1:0;
                cntZer+= (mod==0)?1:0;
            }
            ans += cntOne*cntZer*pow(2,i);
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
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends