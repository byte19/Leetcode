//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
        unordered_map<char,char> map;
        if(s.size()!=t.size()) return false;
        int i=0;
        while(i<s.size()) {
            if(map.find(s[i])==map.end()) {
                for(auto it:map) {
                    if(it.second == t[i]) return false;
                }
                map[s[i]] = t[i];
            }
            else {
                if(map[s[i]]!=t[i]) return false;
            }
            i++;
        }
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends