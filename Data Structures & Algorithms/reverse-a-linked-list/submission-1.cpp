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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        while(curr!=NULL){
            nex = curr->next;
            curr->next = prev;
            prev= curr;
            curr = nex;
        }
        return prev;
    }
};



// NULL->0->1 -> 2 -> 3
// prev curr next
// next = 1
// curr->next

// NULL<-0  1
//       prev     next
