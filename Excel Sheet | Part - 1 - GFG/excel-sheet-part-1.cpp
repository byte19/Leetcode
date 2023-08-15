//{ Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string res = "";
        bool prev = false;
        while(N>0) {
            int val = N%26;
            
            if(val==0) res+= 'Z',prev=true;
            else res += 'A' + (val - 1);
            
            
            if(prev) N = N/26-1,prev=false;
            else N=N/26;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
    
// } Driver Code Ends