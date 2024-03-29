//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> candy(n,1);
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]) candy[i]= candy[i+1] + 1;
            }
            else if(i==n-1){
                if(ratings[i]>ratings[i-1]) candy[i]=candy[i-1] + 1;
            }
            
            else{
                if(ratings[i] > ratings[i-1] && ratings[i]>ratings[i+1]) candy[i] = max(candy[i-1],candy[i+1]) + 1;
                else if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1] + 1;
                else if(ratings[i] > ratings[i+1]) candy[i] = candy[i+1] + 1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && candy[i]<=candy[i+1]) candy[i] = candy[i+1]+1;
        }
        int res=0;
        for(int i=0;i<n;i++) res+=candy[i];
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends