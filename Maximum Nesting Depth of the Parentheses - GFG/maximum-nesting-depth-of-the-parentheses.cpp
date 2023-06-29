//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int openPar = 0;
        int ans = 0;
        for(int i=0;s[i]!='\0';i++) {
            if(s[i]=='(') openPar++;
            else if(s[i]==')') openPar--;
            if(openPar > ans) ans = openPar;
            
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends