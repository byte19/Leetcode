class Solution(object):
    def busyStudent(self, startTime, endTime, queryTime):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type queryTime: int
        :rtype: int
        """
        numStudents = 0
        
        for i in range(len(startTime)):
            if startTime[i]<=queryTime and queryTime <= endTime[i]:
                numStudents+=1
        return numStudents
        