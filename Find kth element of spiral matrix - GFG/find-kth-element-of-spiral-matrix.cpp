//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = m-1;
        int j,i;
        int ind = 0;
        vector<int> spiral;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            j = colStart;
            while(j<=colEnd) {
                spiral.push_back(a[rowStart][j]);
                j++;
            }
            rowStart++;
            
            i = rowStart;
            while(i <= rowEnd) {
                spiral.push_back(a[i][colEnd]);
                i++;
            }
            colEnd--;
            
            j = colEnd;
            while(j>=colStart) {
                spiral.push_back(a[rowEnd][j]);
                j--;
            }
            rowEnd--;
            
            i = rowEnd;
            while(i>=rowStart) {
                spiral.push_back(a[i][colStart]);
                i--;
            }
            colStart++;
        }
        for(int i=0;i<m*n;i++) {
            if(k==1) return spiral[i];
            k--;
        }
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends