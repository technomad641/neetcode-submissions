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
        if(head == NULL || head->next == NULL) return head;
         ListNode* temp = reverseList(head->next);
         head->next->next = head;
         head->next = NULL;
         return temp;
    }
};

// 4-> 3-> 2-> 1
// 1-> 2-> 3-> 4
// rev(1)
// rev(2)
// rev(3) head = 3, temp = 4
// rev(4)
