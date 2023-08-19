//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    {
        vector<int> arrMin(N,-1);
        vector<int> arrMax(N,-1);
        
        arrMin[0] = A[0];
        arrMax[N-1] = A[N-1];
        
        for(int i=1;i<N;i++) {
            arrMin[i] = min(arrMin[i-1],A[i]);
            arrMax[N-i-1] = max(arrMax[N-i],A[N-i-1]);
        }
        
        int i=0,j=0;
        int ans = 0;
        
        while(i<N && j<N) {
            if(arrMin[i] <= arrMax[j]) {
                ans = max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends