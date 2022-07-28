class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        
        for(int i=0;i<s.size();i++) {
            if(hash.count(s[i])==0) hash[s[i]]=0;
            hash[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++) {
            if(hash[t[i]]==0) return false;
            else hash[t[i]]-=1;
        }
        
        unordered_map<char, int>::iterator it;
        for(it=hash.begin();it!=hash.end();it++) {
            if(hash[it->first]!=0) return false;
        }
        return true;
    }
};