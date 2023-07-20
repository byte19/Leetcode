//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       unordered_map<char,pair<int,int>> map;
       
       for(int i = 0;s[i]!='\0';i++) {
           if(map.find(s[i])== map.end()) {
               map[s[i]].second = i;
           }
           map[s[i]].first++;
       }
       
       int ind = -1;
       char ans = '$';
       for(int i = 0;s[i]!='\0';i++) {
           if(map[s[i]].first == 1) {
               ans = s[i];
               break;
           }
       }
       return ans;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends