//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeInitialZeroes(const string& input) {
    size_t numZeroes = input.find_first_not_of('0');
    return (numZeroes == string::npos) ? "0" : input.substr(numZeroes);
}
    string removeKdigits(string S, int k) {
        stack<char> st;
        
        for(int i=0;i<S.size();i++) {
            while(k>0 && !st.empty() && st.top() > S[i]) {
                st.pop();
                k--;
            }
            st.push(S[i]);            
        }
        while(k>0) {
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        string result = removeInitialZeroes(res);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends