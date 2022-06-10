class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        vector<int> curr(n,0);
        for(int j=0;j<n;j++) prev[j] = matrix[n-1][j];
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ld=1e9,rd=1e9,d=1e9;
                if(j-1>=0) ld = matrix[i][j] + prev[j-1];
                d = matrix[i][j] + prev[j];
                if(j+1<n) rd = matrix[i][j] + prev[j+1];
                
                curr[j] = min(ld,min(d,rd));
            }
            prev = curr;
        }
        int mini = 1e9;
        
        for(int i=0;i<n;i++){
            if(prev[i]<mini) mini = prev[i];
        }
        
        return mini;
    }
};