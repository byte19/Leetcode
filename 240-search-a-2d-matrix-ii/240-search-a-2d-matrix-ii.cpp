class Solution {
public:
    bool binarySearch(int end,vector<int>& mat,int target) {
        int start=0;
        end = end-1;
        while(start <= end) {
            int mid = (start + end)/2;
            
            if(mat[mid]==target) return true;
            
            if(mat[mid] > target) end = mid-1;
            if(mat[mid] < target) start = mid+1;
        }
        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++) {
            if(matrix[i][n-1]==target || matrix[i][0]==target) return true;
            
            if(matrix[i][n-1] > target && matrix[i][0] < target) {
                if(binarySearch(n,matrix[i],target)) return true;
            }
        }
        return false;
    }
};