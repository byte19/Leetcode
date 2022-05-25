class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        ans = {}
        for i in list1:
            if i in list2:
                ans[i] = list1.index(i) + list2.index(i)
        ans_list = []
        for k,v in ans.items():
            if v == ans[min(ans, key=lambda x: ans[x])]:
                ans_list.append(k)
        return ans_list