class Solution:
    def maximum69Number (self, num: int) -> int:
        numS = str(num)
        res=""
        stopped = False
        for i in range(len(numS)):
            if(numS[i]=='6' and stopped==False):
                res+='9'
                stopped=True
            else: res+=numS[i]
        return int(res)