class Solution {
    int dp[][];
    int m = 1000000007;
    public int kInversePairs(int n, int k) {
        dp = new int[2][k+1];
        return helper(n,k,dp);
    }
    private int helper(int n , int k , int dp[][]){
        
           for(int i =0;i<=n;i++){
               for(int j =0;j<dp[0].length;j++){
                   if(j> i*(i-1)/2) dp[1][j] = 0;
                   else if(j==0||j==i*(i-1)/2) dp[1][j] = 1;
                   else{
                       dp[1][j] = ((dp[1][j-1]%m) + (dp[0][j]%m))%m;
                       if(j>=i) dp[1][j] = ((dp[1][j]%m) - (dp[0][j-i]%m))%m;
                   }
               }
               for(int j =0;j<dp[0].length;j++){ // save current state
                   // as parent state for next state 
                   dp[0][j] = dp[1][j];
                   dp[1][j] = 0;
               }
           }
          return (dp[0][k] + m)%m;
    }
}