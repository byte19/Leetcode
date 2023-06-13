//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int binarysearch(vector<long long>& arr, long long n, long long k) {
        int i = 0;
        int j = n-1;
        
        while(i<j) {
            if(i==j) return i;

            int mid = (i+j)/2;
            if(arr[mid] > k) j = mid-1;
            else i = mid+1;
        }
        return j;
    }
    int findFloor(vector<long long> v, long long n, long long x){
        
        int ind = binarysearch(v,n,x);
        if(ind==0 || ind==-1) return -1;
        else {
            if(v[ind] > x) return ind-1;
            return ind;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends