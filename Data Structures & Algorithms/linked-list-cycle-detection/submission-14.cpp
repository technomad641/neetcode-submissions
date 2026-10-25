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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast->next){
            slow = slow->next;
            if(fast->next->next)fast = fast->next->next;
            else if(slow != fast)  return false; // cannot move forward so just check
            if(slow == fast) return true;
        }
        return false;
    }
};
