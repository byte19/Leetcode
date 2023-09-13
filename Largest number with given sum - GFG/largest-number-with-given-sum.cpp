//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int N, int S)
    {
        string res = "";
        while(N>0) {
            if(S>9) {
                res+='9';
                S-=9;
            }
            else if(S>0) {
                res+=to_string(S);
                S=0;
            }
            else res+='0';
            N--;
        }
        if(S>0) return "-1";
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends