class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> dp(26, 0);
        for(auto &i : words2)
        {
            vector<int> new_dp(26, 0);
            for(auto &j : i)
                new_dp[j - 'a']++;
            
            for(int i = 0; i < 26; i++)
                dp[i] = max(dp[i], new_dp[i]);
        }
        
        vector<string> ans;
        for(auto &i : words1)
            if(helper(i, dp))
                ans.push_back(i);
        
        return ans;
    }
    
    bool helper(string &s, vector<int> &dp)
    {
        vector<int> new_dp(26, 0);
        for(auto &i : s)
            new_dp[i - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(dp[i] > new_dp[i])
                return false;
        
        return true;
    }
};