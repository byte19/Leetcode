//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int l = 0, h = n-1;
        int mini = 1e9;
        int ind = -1;
        while(l<=h) {
            int mid = (l+h)/2;
            
            if(arr[mid] < mini) {
                mini = arr[mid];
                ind = mid;
            }
            
            // right sorted then dont check because mid element always smaller than all elements at right
            if(arr[mid] <= arr[h]) h = mid-1;
            
            // left sorted then dont check because left element always smaller than all elements till mid
            else if(arr[l] <= arr[mid]) l = mid+1;
        }
        return ind;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends