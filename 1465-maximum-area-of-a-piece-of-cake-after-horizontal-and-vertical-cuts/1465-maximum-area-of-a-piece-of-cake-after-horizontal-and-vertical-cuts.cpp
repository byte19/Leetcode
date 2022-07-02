#include<bits/stdc++.h>

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        
        int last = 0;
        int maxHt = 0;
        for(int i=0;i<n;i++){
            maxHt = max(maxHt,horizontalCuts[i]-last);
            last = horizontalCuts[i];
        }
        maxHt = max(maxHt,h-last);
        
        
        last = 0;
        int maxWd = 0;
        for(int i=0;i<m;i++){
            maxWd = max(maxWd,verticalCuts[i]-last);
            last = verticalCuts[i];
        }
        maxWd = max(maxWd,w-last);
        
        
        return ((long long int)maxHt*maxWd)%mod;
    }
};