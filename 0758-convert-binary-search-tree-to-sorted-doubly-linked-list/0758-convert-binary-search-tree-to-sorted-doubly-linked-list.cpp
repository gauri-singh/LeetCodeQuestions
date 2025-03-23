/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
Node* prev=nullptr;
Node* first=nullptr;
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return nullptr;
        }
        dfs(root);
        //connecting first and last
        first->left=prev;
        prev->right=first;
        return first;
    }
    void dfs(Node* node){
         if(node){
            dfs(node->left);
            if(!first){
                first=node;
            }
            if(prev){
                prev->right=node;
                node->left=prev;
            }
            prev=node;
            dfs(node->right);
         }
        
    }
    
};