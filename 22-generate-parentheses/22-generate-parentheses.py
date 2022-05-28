class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans,n2=[],n<<1;
        def go(o=0,c=0, built=""):
            if o+c==n2:
                ans.append(built);
                return;
            if o < n: go(o+1,c,built+'(');
            if c < o: go(o,c+1,built+')');
        go();
        return ans;