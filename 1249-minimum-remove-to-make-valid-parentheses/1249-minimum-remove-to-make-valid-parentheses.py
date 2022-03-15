class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        removing_idx= set()
        st = []
        
        for i, ch in enumerate(s):
            if ch.isalpha():
                continue
            if not st:
                if ch == ")":
                    removing_idx.add(i)
                elif ch == "(":
                    st.append(i)
            else:
                if ch == "(":
                    st.append(i)
                else:
                    st.pop()
                            
        while st:
            removing_idx.add(st.pop())
            
        ans = ""
        
        for i, ch in enumerate(s):
            if i not in removing_idx:
                ans += ch
                
        return ans