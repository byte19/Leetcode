//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int maxi = 0;
    int mini = 1e9;
    for(int i=0;i<n;i++) {
        maxi = max(a[i],maxi);
        mini = min(a[i],mini);
    }
    // vector<int> og;
    // for(int i=1;i<=maxi;i++) og.push_back(i);
    
    int i=mini;
    int j=0;
    while(i<maxi) {
        if(i==a[j]){
            i++;
            j++;
        }
        else{
            k--;
            if(k==0) return i;
            else {
                i++;
            }
        }
    }
    return -1;
}