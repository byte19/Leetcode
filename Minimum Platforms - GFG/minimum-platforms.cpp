//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=1,j=0;
    	int max_need = 0, curr_need = 1;
    	
    	while(i<n && j<n) {
    	    if(arr[i] <= dep[j]) {
    	        curr_need++;
    	        i++;
    	    }
    	    else if(dep[j] < arr[i]) {
    	        curr_need--;
    	        j++;
    	    }
    	    
    	    max_need = max(curr_need,max_need);
    	}
    	
    	return max_need;
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends