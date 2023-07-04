//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        stack<string> st;
        int len = s.length();
        for(int i = 0; i<len; i++)
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
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                st.push("(" + t2 + ch + t1 + ")");
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends