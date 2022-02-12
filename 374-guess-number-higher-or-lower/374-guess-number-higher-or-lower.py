# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        beg, end = 1, n
        while beg <= end:
            mid = (beg + end)//2
            t = guess(mid)
            if t == 0: return mid
            if t == -1: end = mid - 1
            if t == 1:  beg = mid + 1
        