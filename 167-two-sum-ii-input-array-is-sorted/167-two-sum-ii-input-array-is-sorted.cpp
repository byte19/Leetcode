class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i=0;
        vector<int> res;
        int j = numbers.size()-1;
        while(i<j){
            
            if(numbers[i]+numbers[j] > target) j-=1;
            else if(numbers[i]+numbers[j] < target) i+=1;
            else{    
                res.push_back(i+1);
                res.push_back(j+1);
                break;
            }        
        }
        return res;
    }
};