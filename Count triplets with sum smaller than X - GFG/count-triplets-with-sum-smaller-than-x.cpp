//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    ll s = 0;
	    ll c = 0;
	    for(int i=0;i<n;i++) {
	        int j = i+1, k = n-1;
	        while(j<k) {
	            s = arr[i] + arr[j] + arr[k];
	            if(s < sum) {
	                c+=k-j;
	                j++;
	            }
	            else k--;
	        }
	    }
	    return c;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends