class Solution(object):
    def countMatches(self, items, ruleKey, ruleValue):
        """
        :type items: List[List[str]]
        :type ruleKey: str
        :type ruleValue: str
        :rtype: int
        """

        keys = {'type': 0, 'color': 1, 'name': 2}
        return sum(1 for item in items if item[keys[ruleKey]] == ruleValue)