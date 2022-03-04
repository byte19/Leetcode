class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        visit = [False]*(len(rooms))

        stack = []
        stack.append(0)
        while stack:
            curr = stack.pop()
            if visit[curr]==False:
                visit[curr] = True
                for adj in rooms[curr]:
                    stack.append(adj)
        
        for i in range(len(visit)):
            if visit[i]==False:
                return False
        return True
        