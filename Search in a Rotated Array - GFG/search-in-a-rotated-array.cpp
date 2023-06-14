//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        // int n = nums.size();
        int low = l, high = h,target = key;
        
        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid]==target) return mid;

            // left half sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= target && nums[mid]>=target) {
                    high = mid-1;
                }
                else low = mid+1;
            }

            // right sorted
            if(nums[mid] <= nums[high]) {
                if(nums[mid] <= target && nums[high] >= target) low = mid+1;
                else high = mid-1;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends