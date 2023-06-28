//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        vector<char> st;
        string res = "";
        for(int i=0;s[i]!='\0';i++) {
            if(s[i]=='(') {
                st.push_back('(');
                if(st.size()==1) continue;
                else {
                    res+='(';
                }
            }
            else {
                st.pop_back();
                if(st.size()==0) continue;
                else {
                    res+=')';
                }
            }
        }
        return res;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends