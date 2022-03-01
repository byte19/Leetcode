class Solution(object):
    def transpose(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        allcols = list(zip(*matrix))
        allcols = list(map(list,allcols))
        return allcols