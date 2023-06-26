//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fives = 0;
        int tens = 0;

        for(auto bill: bills) {
            if(bill==5) fives++;
            else if(bill==10) {
                tens++;
                fives--;
            }
            else if(tens > 0) {
                tens--;
                fives--;
            }
            else {
                fives-=3;
            }

            if(fives<0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends