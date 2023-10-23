//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends



bool metaStrings (string S1, string S2)
{
    int samePos = 0;
    int diffPos1 = -1, diffPos2 = -1;
    int n = S1.size();
    for(int i=0;i<n;i++) {
        if(S1[i]==S2[i]) samePos++;
        else {
            if(diffPos1==-1) diffPos1 = i;
            else diffPos2 = i;
        }
    }
    if(n-samePos > 2 || samePos==n) return false;
    if(S1[diffPos1]!=S2[diffPos2] || S1[diffPos2]!=S2[diffPos1]) return false;
    
    return true;
}