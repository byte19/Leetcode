//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int nums1[], int nums2[], 
                                 int m, int n)
    {
        vector<int> ans;
        
        sort(nums2, nums2+n);
        int i=0;
        for(int i=0;i<m;i++){
            int s=0;
            int e=n-1;
            while(s<=e){
                int mid= (s+e)/2;
                if(nums2[mid]<=nums1[i])
                    s= mid+1;
                else
                    e= mid-1;
            }
            ans.push_back(e+1);
        }
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
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends