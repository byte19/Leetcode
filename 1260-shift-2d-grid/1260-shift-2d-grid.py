class Solution(object):
    def shiftGrid(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        lis = []
        for x in grid:
            for i in x:
                lis.append(i)
        
        if k >= len(lis):
            k = k % len(lis)
        lis = lis[-k:] + lis[:-k]
        k = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                grid[i][j] = lis[k]
                k+=1
        return grid