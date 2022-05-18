class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        def backtrack(index, target, res=[], output=[]):
            if target == 0:
                output.append(res[:])
                return
            
            if index >= len(candidates):
                return
            
            prev = -1
            for i in range(index, len(candidates)):
                if candidates[i] != prev and target - candidates[i] >= 0:
                    res.append(candidates[i])
                    backtrack(i+1, target-candidates[i])
                    res.pop()
                prev = candidates[i]
            return output
        
        return backtrack(0, target)