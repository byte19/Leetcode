//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int bSearch(int arr[],int n,int x){
    int i = 0, j = n-1;
    
    while(i<=j) {
        int mid = (i+j)/2;
        
        if(arr[mid]==x) return mid;
        
        if(arr[mid] > x) j = mid-1;
        else i = mid+1;
    }
    return -1;
}
vector<int> find(int arr[], int n , int x )
{
    int idx = bSearch(arr,n,x);
    
    if(idx==-1) return {-1,-1};
    int i = idx,j=idx;
    // cout <<idx<<endl;
    
    while(i>=0 || j < n) {
        if(arr[i]==x) i--;
        if(arr[j]==x) j++;
        
        if(arr[i]!=x && arr[j]!=x) break;
    }
    return {i+1,j-1};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends