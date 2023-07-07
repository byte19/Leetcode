//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int fun(long long arr[],int n) {
        stack<long long> s1 , s2;
        long long * a1 = new long long[n];
        long long * a2 = new long long[n];
        for (int i = 0 ; i < n ; i++){
            while (!s1.empty() && arr[s1.top()] >= arr[i]){
                s1.pop();
            }
            while (!s2.empty() && arr[s2.top()] >= arr[n-i-1]){
                s2.pop();
            }
            s1.empty() ? a1[i] = -1 : a1[i] = s1.top();
            s2.empty() ? a2[n-i-1] = n : a2[n-i-1] = s2.top();
            s1.push(i);
            s2.push(n-i-1);
        }
        long long ans = -1;
        for (int i = 0 ; i < n ; i++){
            long long a = (a2[i] - a1[i]-1)*arr[i];
            ans ? ans = std::max(ans,a) : ans = a;
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        long long height[m] = {0};
        int maxA = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(M[i][j]==1) height[j]++;
                else height[j]=0;
            }
            maxA = max(maxA,fun(height,m));
        }
        return maxA;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends