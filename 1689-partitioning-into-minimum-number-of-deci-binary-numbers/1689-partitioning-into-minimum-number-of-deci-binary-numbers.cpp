class Solution {
public:
    int minPartitions(string n) {
        int i=0;
        int count = 0;
        while(i < n.size()){
            if(int(n[i])>count) count = int(n[i]);
            i+=1;
        }
        return count%48;
    }
};