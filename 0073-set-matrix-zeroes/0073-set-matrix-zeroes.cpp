class Solution {
public:
    void setZ(vector<vector<int>>& matrix,vector<int>& pos,int m,int n) {
        for(int i=0;i<m;i++) {
            matrix[i][pos[1]]=0;
        }
        for(int i=0;i<n;i++) {
            matrix[pos[0]][i]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> pos;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0){
                    vector<int> v1;
                    v1.push_back(i);
                    v1.push_back(j);
                    pos.push_back(v1);
                }
            }
        }
        for(int i=0;i<pos.size();i++) {
            setZ(matrix,pos[i],m,n);
        }
    }
};