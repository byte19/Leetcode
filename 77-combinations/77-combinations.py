class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        
        res = []
        nums = [i for i in range(1,n+1)]
        
        def solve(ind,nums,lis,k):
            if len(lis)==k:
                b = []
                b.extend(lis)
                res.append(b)
                return
            
            for i in range(ind,len(nums)):
                lis.append(nums[i])
                solve(i+1,nums,lis,k)
                lis.pop()
        
        solve(0,nums,[],k)
        
        return res