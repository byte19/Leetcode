//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &g, vector<int> &s) {
        // code here
        int children = g.size();
        int cookies = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans = 0;
        int i = 0, j = 0;
        while(j<cookies && i < children) {
            if(s[j] >= g[i]) {
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends