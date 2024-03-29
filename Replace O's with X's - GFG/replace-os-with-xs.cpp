//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            if(mat[i][0]=='O') q.push({i,0});
            if(mat[i][m-1]=='O') q.push({i,m-1});
        }
        for(int i=0;i<m;i++) {
            if(mat[0][i]=='O') q.push({0,i});
            if(mat[n-1][i]=='O') q.push({n-1,i});
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();
            mat[i][j] = 'Y';
            for(int k = 0;k<4;k++) {
                int newRow = i+delrow[k];
                int newCol = j+delcol[k];
                
                if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && mat[newRow][newCol]=='O') {
                    mat[newRow][newCol] = 'Y';
                    q.push({newRow,newCol});
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='Y') mat[i][j]='O';
                else mat[i][j]='X';
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends