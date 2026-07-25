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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* x = head;
        int ans =0;
        while(x!=NULL){
            ++ans;
            x = x->next;
        }
        int pos = ans-n+1;
        ListNode* DN = new ListNode();
        DN->next = head;
        ListNode* P = DN;
        for(int i=0;i<pos-1;i++){
            P = P->next;
        }
        if(P->next !=NULL){
            P->next = P->next->next;
        }
        return DN->next;
    }
};
