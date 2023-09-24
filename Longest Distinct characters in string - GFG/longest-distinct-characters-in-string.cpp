//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int chars[26] = {0};
    int n = s.size();
    if(n==0) return 0;
    int ans = 0;
    int i=0, j = 0;
    while(j<n) {
        chars[s[j]-'a']+=1;
        if(chars[s[j]-'a'] > 1) {
            while(chars[s[j]-'a'] > 1) {
                chars[s[i]-'a']-=1;
                i++;
            }
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}