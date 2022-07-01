class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x:x[1],reverse=True)
        i = 0
        res = 0
        n = len(boxTypes)
        while truckSize>0 and i<n:
            if(truckSize > boxTypes[i][0]):
                res += boxTypes[i][0]*boxTypes[i][1]
                truckSize -= boxTypes[i][0]
            else:
                res += truckSize*boxTypes[i][1]
                truckSize=0
            i+=1
        return res