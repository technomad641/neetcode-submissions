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

// 1-> 2-> 5 -> 7 -> 11
// 1 -> 4 -> 9 -> 12
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* head = NULL;
        ListNode* curr = list2;
        ListNode* temp = NULL;
        while( head1 && head2){
            if(head1->val >= head2-> val){
                temp = new  ListNode(head2-> val);
                head2 = head2->next;
            }else{
                temp = new  ListNode(head1-> val);
                head1 = head1->next;
            }
            if(head == NULL) {
                head = temp;
                curr = head;
            }
            else{
                curr-> next = temp;
                curr = temp;
            }
        }
        if(head1){
            //curr = head1;
            if(head == NULL) {
                head = head1;
            }else{
                curr->next= head1;
                curr = head1;
            }
            
            //head1 = head1->next;
        }
        if(head2){
            if(head == NULL) {
                head = head2;
            }else{
                curr->next= head2;
                curr = head2;
            }
        }
        return head;
    }
};
