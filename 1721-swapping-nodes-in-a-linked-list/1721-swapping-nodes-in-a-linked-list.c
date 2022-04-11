/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    
    struct ListNode* temp = head;
    int len=0;
    while(temp){
        len++;
        temp = temp->next;
    }
    struct ListNode* beg;
    struct ListNode* end;
    int starti = k;
    int endi = len-k+1;
    int i=1;
    temp = head;
    while(temp){
        if(i==starti)
        beg = temp;
        
        if(i==endi)
        end = temp;
        
        temp = temp->next;
        i++;
    }
    
    int tempo;
    tempo = beg->val;
    beg->val = end->val;
    end->val = tempo;
    
    return head;

}