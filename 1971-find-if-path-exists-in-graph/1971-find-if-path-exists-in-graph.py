class Solution(object):
    def validPath(self, n, edges, src, dst):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """
        def ELtoAL(edges):
            graph = {}
            for edge in edges:
                u,v = edge
                if u not in graph:
                    graph[u] = []
                if v not in graph:
                    graph[v] = []
                graph[u].append(v)
                graph[v].append(u)
            return graph
        AdjLis = ELtoAL(edges)
        stack = []
        stack.append(src)
        dict = {}
        while stack:
            curr = stack.pop()
            if curr==dst:
                return True
            for v in AdjLis[curr]:
                if v in dict:
                    continue
                else:
                    stack.append(v)
                    dict[v] = True
        return False