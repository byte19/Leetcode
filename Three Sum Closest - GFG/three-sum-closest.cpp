//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int ans = 0;
        int minDiff = 1e9;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++) {
            int j = i+1,k=arr.size()-1;
            
            while(j<k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum==target) return sum;
                
                if(abs(sum-target)==minDiff) ans = max(ans,sum);
                
                if(minDiff > abs(sum-target)) {
                    ans = sum;
                    minDiff = abs(sum-target);
                }
                if(sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends