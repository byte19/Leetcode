class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        flag = [0]*len(tiles)
        res = []
        dict = {}
        def solve(tiles,flag,lis):
            if len(lis)>0 and "".join(lis) not in dict:
                li_copy = []
                li_copy.extend(lis)
                dict["".join(lis)] = 1
                res.append(li_copy)
            
            for i in range(len(tiles)):
                if flag[i]==0:
                    flag[i]=1
                    lis.append(tiles[i])
                    solve(tiles,flag,lis)
                    lis.pop()
                    flag[i]=0
        
        solve(tiles,flag,[])
        
        return len(res)