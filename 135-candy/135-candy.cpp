class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> candy(n,1);
        for(int i=0;i<n;i++){
            if(i==0){
                if(ratings[i]>ratings[i+1]) candy[i]= candy[i+1] + 1;
            }
            else if(i==n-1){
                if(ratings[i]>ratings[i-1]) candy[i]=candy[i-1] + 1;
            }
            
            else{
                if(ratings[i] > ratings[i-1] && ratings[i]>ratings[i+1]) candy[i] = max(candy[i-1],candy[i+1]) + 1;
                else if(ratings[i] > ratings[i-1]) candy[i] = candy[i-1] + 1;
                else if(ratings[i] > ratings[i+1]) candy[i] = candy[i+1] + 1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && candy[i]<=candy[i+1]) candy[i] = candy[i+1]+1;
        }
        int res=0;
        for(int i=0;i<n;i++) res+=candy[i];
        return res;
    }
};