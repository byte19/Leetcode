class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1,val=0;
        for(int i=n;i>=0;i--){
            if(val==0 && s[i]==' ') continue;
            else if(val!=0 && s[i]==' ') break;
            else val++;
        }
        return val;
    }
};