class Solution {
public:
    int fib(int n) {
        int pp=0;
        int p=1;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
            int curr = pp + p;
            pp = p;
            p = curr;
        }
        return p;
    }
};