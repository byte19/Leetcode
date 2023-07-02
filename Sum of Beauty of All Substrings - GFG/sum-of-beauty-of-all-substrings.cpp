//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans= 0;
        int n = s.size();
        for(int i=0;i<n;i++) {
            int chars[26] = {0};
            for(int j = i;j<n;j++) {
                int mx = INT_MIN, mn = INT_MAX;
                chars[s[j]-'a']++;
                for(auto x: chars) {
                    if(x!=0) {
                        mx = max(mx,x);
                        mn = min(mn,x);
                    }
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends