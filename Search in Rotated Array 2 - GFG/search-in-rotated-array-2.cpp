//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int Key) {
        // Code here
        int n = N;
        int low = 0, high = n-1;
        int target = Key;
        
        while(low <= high) {
            int mid = (low+high)/2;

            if(nums[mid]==target) return true;

            if(nums[low]==nums[mid] && nums[mid]==nums[high]) {
                high--;
                low++;
                continue;
            }
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

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends