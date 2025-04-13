/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map <Node*,NodeCopy*> oldToNew;
        createCopies(oldToNew,root);
        connectCopies(oldToNew,root);
        return oldToNew[root];
    }
    void createCopies(unordered_map <Node*,NodeCopy*>& oldToNew, Node* node) {
        if(!node){
            return;
        }
        oldToNew[node]= new NodeCopy(node->val);
        createCopies(oldToNew,node->left);
        createCopies(oldToNew,node->right);
    }
    void connectCopies(unordered_map <Node*,NodeCopy*>& oldToNew, Node* node) {
        if(!node){
            return;
        }
        NodeCopy* copy= oldToNew[node];
        copy->left=oldToNew[node->left];
        copy->right=oldToNew[node->right];
        copy->random=oldToNew[node->random];
        connectCopies(oldToNew,node->left);
        connectCopies(oldToNew,node->right);
    }
};