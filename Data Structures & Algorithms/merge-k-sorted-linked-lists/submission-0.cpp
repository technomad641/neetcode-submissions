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
    struct Compare {
                    bool operator() (const ListNode *a, const ListNode *b) {
                        return a->val > b->val;
                    }
                };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode*>, Compare> PQ;
        ListNode* head = NULL;
         ListNode* tail = NULL;
        int sz = lists.size();
        for(int i=0;i<sz;i++){
            PQ.push(lists[i]);
        }
        while(!PQ.empty()){
            ListNode* x = PQ.top(); PQ.pop();
            if(x->next != NULL) PQ.push(x->next);
            ListNode* temp = x;
            if(head == NULL){
                head = temp;
            }else{
                tail->next = temp;
            }
            tail = temp;
        }
        return head;
        
    }
};
