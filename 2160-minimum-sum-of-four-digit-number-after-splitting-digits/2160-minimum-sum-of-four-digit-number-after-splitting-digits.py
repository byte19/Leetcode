class Solution(object):
    def minimumSum(self, num):
        """
        :type num: int
        :rtype: int
        """
        li = [''.join(p) for p in itertools.permutations(str(num))]
        min_ = float('inf')
        for i in range(len(li)):
            if(int(li[i][:2]) + int(li[i][2:]) < min_):
                min_ = int(li[i][:2]) + int(li[i][2:])
        
        return min_
        