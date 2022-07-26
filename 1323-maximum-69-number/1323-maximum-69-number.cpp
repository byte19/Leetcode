#include<bits/stdc++.h>
class Solution {
public:
    int maximum69Number (int num) {
        bool stopped = false;
        string res;
        string numS = to_string(num);
        for(int i=0;i<numS.size();i++) {
            if(numS[i]=='6' && stopped==false) {
                res+='9';
                stopped=true;
            }
            else res+=numS[i];
        }
        return stoi(res);
    }
};