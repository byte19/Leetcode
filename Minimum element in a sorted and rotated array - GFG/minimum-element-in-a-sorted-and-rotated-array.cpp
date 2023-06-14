//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l = 0, h = n-1;
        int mini = 1e9;
        while(l<=h) {
            int mid = (l+h)/2;
            mini = min(mini,arr[mid]);
            
            // right sorted then dont check because mid element always smaller than all elements at right
            if(arr[mid] <= arr[h]) h = mid-1;
            
            // left sorted then dont check because left element always smaller than all elements till mid
            else if(arr[l] <= arr[mid]) l = mid+1;
        }
        return mini;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends