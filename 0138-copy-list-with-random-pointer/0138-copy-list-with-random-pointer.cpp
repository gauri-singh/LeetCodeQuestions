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
        unordered_map<Node*,Node*> oldToCpy;
        Node* curr = head;
        oldToCpy[nullptr]=nullptr;
        while(curr){
            Node* copy = new Node(curr->val);
            oldToCpy[curr]=copy; // key -> val
            curr=curr->next;
        }
        curr= head; // reassigning
        while(curr){
            Node* copy = oldToCpy[curr];
            copy->next=oldToCpy[curr->next];  // important to use the copied next and random nodes
            copy->random=oldToCpy[curr->random]; // therefore extract the current copy nodes from hashmap
            curr=curr->next;
        }

        return oldToCpy[head]; // copy version of head
    }
};