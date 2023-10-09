//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[],ll temp[],ll left,ll mid,ll right) {
        ll i, j, k;
        ll inv_count = 0;
     
        i = left;
        j = mid;
        k = left;
        while((i<=mid-1) &&(j<=right)) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                inv_count = inv_count + (mid - i);
            }
        }
        
        while(i<mid) temp[k++] = arr[i++];
        while(j<=right) temp[k++] = arr[j++];
        
        for(i = left;i<=right;i++) arr[i] = temp[i];
        
        return inv_count;
        
    }
    ll merge_sort(ll low,ll high,ll temp[],ll arr[],ll N) {
        ll cntInv = 0;
        if(low < high) {
            ll mid = (low+high)>>1;
            cntInv += merge_sort(low,mid,temp,arr,N);
            cntInv += merge_sort(mid+1,high,temp,arr,N);
            cntInv += merge(arr,temp,low,mid+1,high);
        }
        
        return cntInv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        ll temp[N];
        return merge_sort(0,N-1,temp,arr,N);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends