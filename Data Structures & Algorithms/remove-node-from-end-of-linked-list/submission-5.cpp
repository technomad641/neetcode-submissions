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
        
        ListNode* nTHnODE = new ListNode();
        ListNode* temp = nTHnODE;
        //ListNode* tempHead = temp;
        nTHnODE-> next = head;
        ListNode* curr = head;
        ListNode* prev = nTHnODE;
        for(int i=0;i<n;i++){
            curr = curr->next;
        }
        //if(curr == NULL) return NULL;
        while(curr){
            nTHnODE = nTHnODE->next;
            curr = curr->next;
        }
        //if(nTHnODE ->next) nTHnODE->val = nTHnODE->next->val;
        if(nTHnODE ->next) nTHnODE->next = nTHnODE->next->next;
        return temp->next;
    }
};
