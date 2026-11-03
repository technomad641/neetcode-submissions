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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        ListNode* newHEAD = NULL;
        if(list1 == NULL) return list2;
        if(list2==NULL) return list1;
        while(list1!= NULL && list2!= NULL){
            if(list1->val <=list2->val){
                prev = new ListNode(list1->val);
                if(newHEAD == NULL) newHEAD = prev;
                list1= list1->next;
            }else{
                prev = new ListNode(list2->val);
                if(newHEAD == NULL) newHEAD = prev;
                list2= list2->next;
            }
            if(temp==NULL) temp = prev;
            else{
                temp->next = prev;
                temp = prev;
            }   
        }

        if(list1!=NULL){
            temp->next = list1;
        }

        if(list2!=NULL){
            temp->next = list2;
        }
        return newHEAD;
        
    }
};
