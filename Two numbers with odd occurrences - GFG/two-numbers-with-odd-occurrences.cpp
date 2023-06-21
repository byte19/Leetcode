//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int allXor = Arr[0];
        for(long long int i=1;i<N;i++) allXor ^= Arr[i];
        
        int setBit = 0;
        for(int i=0;i<32;i++) {
            int curr = 1<<i;
            if(curr & allXor) {
                setBit = curr;
                break;
            }
        }
        
        vector<long long int> ans;
        long long int xorSet = 0;
        for(long long int i=0;i<N;i++) {
            if(Arr[i] & setBit) {
                xorSet ^= Arr[i];
            }
        }
        ans.push_back(xorSet);
        
        long long int xorNotset = 0;
        for(long long int i=0;i<N;i++) {
            if((Arr[i] & setBit) == 0) {
                xorNotset ^= Arr[i];
            }
        }
        ans.push_back(xorNotset);
        
        if(ans[1] > ans[0]) swap(ans[0],ans[1]);
        
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends