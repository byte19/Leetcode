//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	long long maxProduct(vector<int> arr, int n) {

    
    long long max_val = arr[0];
    long long min_val = arr[0];
    long long max_product = arr[0];
    
    for(int i = 1; i < n; i++) {
        if (arr[i] < 0) swap(max_val, min_val);
        
        max_val = max<long long>(arr[i], max_val * arr[i]);
        min_val = min<long long>(arr[i], min_val * arr[i]);
        
        max_product = max(max_product, max_val);
    }
    return max_product;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends