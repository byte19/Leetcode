/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *temp,*curr,*prev = NULL;
    temp = head;
    while(temp){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
    
}