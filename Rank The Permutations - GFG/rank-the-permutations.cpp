//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string str) {
        int n=str.size();
        long long fact[n+1]={0};
        fact[0]=1;
        long long ans = 1;
        for(int i=1;i<=n;i++) fact[i]=i*fact[i-1];
        
        for(int i=0;i<n-1;i++) {
            int count = 0;
            for(int j=i+1;j<n;j++) {
                if(str[i] > str[j]) count+=1;
            }
            ans+=count*fact[n-i-1];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends