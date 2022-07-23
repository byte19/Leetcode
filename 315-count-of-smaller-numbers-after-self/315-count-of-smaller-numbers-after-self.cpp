struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         return hash1;
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, hash_pair> mp;
    
    void merge(vector<pair<int,int>>& nums, int s1, int e1, int s2, int e2){
        int p1 = s1;
        int p2 = s2;
        
        while(p1 <= e1 and p2 <= e2 ){
            if(nums[p1].first>nums[p2].first){
                p2++;
            }
            else{
                mp[{nums[p1].first, nums[p1].second}] += (p2-s2);
                p1++;
            }
        }
        
        while(p1<=e1){
            mp[{nums[p1].first, nums[p1].second}] += (p2-s2);
            p1++;
        }
       
        sort(nums.begin()+s1, nums.begin()+e2+1);
    }
    
    void mergeSort(vector<pair<int,int>>& nums, int s , int e){
        if(s==e) return;
        int mid = s + (e-s)/2;
        
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, mid, mid+1, e);
    }
    
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({arr[i],i});
        }
        
        mergeSort(nums,0,n-1);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(mp.find({arr[i],i})!=mp.end()){
                ans.push_back(mp[{arr[i],i}]);
            }
            else ans.push_back(0);
        }
        
        return ans;
    }
};