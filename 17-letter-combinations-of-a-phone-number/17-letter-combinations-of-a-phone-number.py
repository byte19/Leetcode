class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "": return []
        res = []
        d = {'2':['a','b','c'],
             '3':['d','e','f'],
             '4':['g','h','i'],
             '5':['j','k','l'],
             '6':['m','n','o'],
             '7':['p','q','r','s'],
             '8':['t','u','v'],
             '9':['w','x','y','z']
            }
        
        
        def solve(i,digits,d,lis):
            if i>=len(digits) and len(lis)==len(digits):
                b = []
                b.extend(lis)
                res.append("".join(b))
                return
            
            for j in range(i,len(digits)):
                temp = d[digits[i]]
                for k in range(len(temp)):
                    lis.append(temp[k])
                    solve(j+1,digits,d,lis)
                    lis.pop()
        
        solve(0,digits,d,[])
        return res
                    