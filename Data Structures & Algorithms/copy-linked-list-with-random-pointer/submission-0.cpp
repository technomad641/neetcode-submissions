/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map< Node*, Node* > cnt;
        Node* temp = head;
        Node* newHead = NULL;
         Node* prev = NULL;
        while(temp){
            Node* ans = new Node(temp->val);
            if(newHead == NULL){
                newHead = ans;
            }
            if(prev == NULL){
                prev = ans;
            }else{
                prev->next = ans;
                prev = ans;
            }
            cnt[temp] = ans;
            temp = temp->next;
        }

        //copy random pointers now
        temp = head;
        Node* t = newHead;
        while(temp){
            t->random = cnt[temp->random];
            temp = temp->next;
            t = t->next;

        }
        return newHead;
    }
};
