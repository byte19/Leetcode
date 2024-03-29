//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        string ans;
        stack<string> st;
        int len = s.length();
        for(int i = len-1; i>=0; i--)
        {
            char ch = s[i];
            if(ch>='a' and ch<='z' || ch>='A' and ch<='Z' || ch>='1' and ch<='9')
            {
                string temp = "";
                temp = temp+ch;
                st.push(temp);
            }
            else
            {
                string res = "";
                res += st.top();
                st.pop();
                res += st.top();
                st.pop();
                res += s[i];
                st.push(res);
            }
        }
     return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends