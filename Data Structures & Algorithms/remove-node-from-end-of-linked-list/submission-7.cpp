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
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        // created a head
        ListNode*temp = dummyHead;
        ListNode*temp2 = dummyHead;
        for(int i=0;i<n;i++) temp = temp->next;
        
        while(temp->next!= NULL){
            temp2 = temp2->next;
            temp = temp->next;
        }
        if(temp2->next != NULL){
            ListNode* p = temp2->next;
            temp2->next = p->next;
            p->next = NULL;
            delete(p);
        }
        return dummyHead->next;
    }
};
