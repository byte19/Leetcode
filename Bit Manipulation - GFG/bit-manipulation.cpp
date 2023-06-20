//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int set = 0;
        int get = 0;
        int clear = 0;
        if(num & (1 << i-1)) get = 1;
        
        if(get) set = num;
        else set = num + pow(2,i-1);
        
        
        clear = set - pow(2,i-1);
        cout << get << " " << set << " " << clear;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends