//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0;
        bool isNeg = false;
        if(str[0]=='-') isNeg = true;
        int tens = 1;
        for(int i=str.size()-1;i>=0;i--) {
            if(i==0 && str[i]=='-') break;
            if(str[i]>='0' && str[i]<='9') {
                int num = str[i]%48;
                ans += tens*num;
                tens = tens*10;
            }
            else return -1;
        }
        if(isNeg) ans = ans - (2*ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends