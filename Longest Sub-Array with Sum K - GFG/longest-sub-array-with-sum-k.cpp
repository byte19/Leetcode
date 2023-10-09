//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mapp;
        
        for(int i=0;i<N;i++) {
            sum += A[i];
            
            if(sum==K) ans = i+1;
            
            if(mapp.find(sum)==mapp.end()) mapp[sum] = i;
            
            if(mapp.find(sum-K)!=mapp.end()) {
                ans = max(ans,i-mapp[sum-K]);
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends