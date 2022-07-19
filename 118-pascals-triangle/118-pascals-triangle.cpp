class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res {{1},{1,1}};
        if(numRows==1) return {res[0]};
        for(int i=2;i<numRows;i++){
            vector<int> temp = res[i-1];
            vector<int> lis;
            lis.push_back(temp[0]);
            for(int j=1;j<temp.size();j++) lis.push_back(temp[j]+temp[j-1]);
            lis.push_back(temp[temp.size()-1]);
            res.push_back(lis);
        }
        return res;
    }
};