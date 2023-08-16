//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string S) {

        set<string> set;
        int N=S.size();
        for(int i=0;i<N;i++){
            int l=i,r=i+1;
            while(l>=0 && r<N && S[l]==S[r]){
                set.insert(S.substr(l,r-l+1));
                l--,r++;
            }
            l=i,r=i;
            while(l>=0 && r<N && S[l]==S[r]){
                set.insert(S.substr(l,r-l+1));
                l--,r++;
            }
        }
        return set.size();
    }


};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends