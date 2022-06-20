class Solution {
public:
    int minimumDifference(vector<int>& a) 
    {
        int n=a.size()/2,sum=0;
        for(int i=0;i<2*n;i++) sum+=a[i];
        
        vector<vector<int>> v(n+1);
        for(int i=0;i<(1<<n);i++)
        {
            int s=0,cnt=0;
            for(int j=0;j<n;j++)
                if(i & (1<<j)) s+=a[j],cnt++;
            v[cnt].push_back(s);
        }
        for(int i=0;i<=n;i++)
            sort(v[i].begin(),v[i].end());
        
        int ans=INT_MAX;
        for(int i=0;i<(1<<n);i++)
        {
            int s=0,cnt=0;
            for(int j=0;j<n;j++)
                if(i & (1<<j)) s+=a[n+j],cnt++;
           
            auto ts=lower_bound(v[n-cnt].begin(),v[n-cnt].end(),sum/2-s);
            if(ts!=v[n-cnt].end())
                ans=min(ans,abs(sum-2*(s+*ts)));
            if(ts!=v[n-cnt].begin())
                ans=min(ans,abs(sum-2*(s+(*--ts))));
        }
        return ans;
    }
};