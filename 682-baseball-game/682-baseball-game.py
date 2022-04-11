class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        lis = []
        for op in ops:
            if op=="+":
                lis.append(lis[-1] + lis[-2])
            elif op=="D":
                lis.append(2*lis[-1])
            elif op=="C":
                lis.pop()
            else:
                lis.append(int(op))
        return sum(lis)