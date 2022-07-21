/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> res;
        ListNode *temp = head;
        while(temp) {
            res.push_back(temp->val);
            temp = temp->next;
        }
        int i = left-1,j=right-1;
        while(i<j) {
            swap(res[i],res[j]);
            i++,j--;
        }
        temp = head;
        i=0;
        while(temp) {
            temp->val = res[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};