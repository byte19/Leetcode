class Solution(object):
    def destCity(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: str
        """
        d=dict(paths)
        x=paths[0][0]
        while x in d:
            x=d[x]
        return x