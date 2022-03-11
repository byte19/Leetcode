class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        
        lt = ["" for i in range(numRows)]
        index= 0 
        length = len(s)
        move_down = True
        move_up = True
        i = 0
        while index<length:
            if move_down:
                lt[i]+=s[index]
                i+=1
            else:
                lt[i]+=s[index]
                i-=1
            index+=1
            if i==0:
                move_down = True
                move_up = False
            elif i == numRows-1:
                move_up=True
                move_down= False
        ans = ""
        for a in lt:
            ans+=a
        return ans
        