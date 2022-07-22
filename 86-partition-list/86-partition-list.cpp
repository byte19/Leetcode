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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head,*headSmall=NULL,*headLarge=NULL;
        if(head==NULL) return 0;
        if(head->next==NULL) return head;
        
        while(temp) {
            if(temp->val >= x) {
                headLarge = temp;
                break;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            if(temp->val < x) {
                headSmall = temp;
                break;
            }
            temp = temp->next;
        }
        
        temp = head;
        if(headSmall && headLarge) {
            ListNode *tempH = headLarge,*tempS=headSmall;
            while(temp) {
                if(temp!=headSmall && temp!=headLarge) {
                    if(temp->val >= x) {
                        tempH->next = temp;
                        tempH = temp;
                    }
                    if(temp->val < x) {
                        tempS->next = temp;
                        tempS = temp;
                    }
                }
                temp = temp->next;
            }
            tempH->next = NULL;
            tempS->next = headLarge;
            return headSmall;
        }
        return head;
    }
};