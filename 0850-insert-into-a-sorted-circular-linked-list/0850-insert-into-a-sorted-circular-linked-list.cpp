/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
             Node* node=new Node(insertVal);
             node->next=node;
             return node;
        }
        Node* prev=head;
        Node* curr= prev->next;
        while(true){
             if (prev->val <= insertVal && insertVal <= curr->val) {
                break;
            }
              // Case 2: At rotation point (max → min)
            if (prev->val > curr->val) {
                if (insertVal >= prev->val || insertVal <= curr->val) {
                    break;
                }
            }
            prev = curr;
            curr = curr->next;

            // Case 3: Full loop with no spot found (e.g., all equal values)
            if (prev == head) {
                break;
            }
        }
        Node* node = new Node(insertVal, curr);
        prev->next = node;
        return head;
    }
};