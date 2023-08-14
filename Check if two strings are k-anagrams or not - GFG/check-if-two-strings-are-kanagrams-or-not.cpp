//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        if(str1.size()!= str2.size()) return 0;
        unordered_map<char,int> map;
        for(auto c:str1) map[c]+=1;
        int s1 = map.size();
        int cnt = 0;
        for(auto c:str2) {
            if(map.find(c)!=map.end()) {
                map[c]-=1;
                if(map[c]==0) {
                    map.erase(c);
                }
            }
            else cnt++;
        }
        return cnt<=k;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends