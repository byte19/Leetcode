//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xo = nums[0];
        for(int i=1;i<nums.size();i++) xo^=nums[i];
        
        int mask = 0;
        
        for(int po=0;po<30;po++)
        {
            if((xo&(1<<po)) > 0) mask = (1<<po);
        }
        
        int num1 = 0;
        int num2 = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]&mask))
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        vector<int> ans {num1,num2};
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends