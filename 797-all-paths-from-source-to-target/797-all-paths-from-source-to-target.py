class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        
        res = []
        
        start = 0
        target = len(graph)-1
        
        def solve(s,t,lis):
            if s==t:
                li_copy = []
                li_copy.extend(lis)
                res.append(li_copy)
                return
            
            
            for j in graph[s]:
                lis.append(j)
                solve(j,t,lis)
                lis.pop()
        
        solve(start,target,[0])
        
        return res