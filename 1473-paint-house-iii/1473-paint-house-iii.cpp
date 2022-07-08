class Solution {
public:
    int dp[105][25][105], inf=1e8+5;
    
    int fun(int i, int c, int t, int m, int n, vector<int>& a, vector<vector<int>>& v){
        if(i==m){
            if(t==0) return 0;
            return inf;
        }
        if(t<0) return inf;
        if(dp[i][c][t]!=-1) return dp[i][c][t];
        int z=inf;
        if(a[i]){
            if(c!=a[i]) z=fun(i+1,a[i],t-1,m,n,a,v);
            else z=fun(i+1,a[i],t,m,n,a,v);
        }
        else{
            for(int k=1; k<=n; k++){
                if(k!=c) z=min(z, fun(i+1,k,t-1,m,n,a,v)+v[i][k-1]);
                else z=min(z, fun(i+1,k,t,m,n,a,v)+v[i][k-1]);
            }
        }
        return dp[i][c][t]=z;
    }
    
    int minCost(vector<int>& a, vector<vector<int>>& v, int m, int n, int t) {
        memset(dp, -1, sizeof dp);
        int ans=fun(0,0,t,m,n,a,v);
        if(ans>=inf) return -1;
        return ans;
    }
};