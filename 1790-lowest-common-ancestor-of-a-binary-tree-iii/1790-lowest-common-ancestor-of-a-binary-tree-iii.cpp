/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
//fast and slow pointer adjacent solution
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* p_copy = p;
        Node* q_copy=q;
        while(p != q){
            //keep running the loop till they meet
            // if one of them gets to root first, set it to the other node, so that in next itearation they reach the parent node same, since the longer node will be switched to shorter path node and vice versa
            p= p!=nullptr? p->parent: q_copy;
            q= q!=nullptr?q->parent: p_copy; 
           
        }
        return p;
    }
//set solution
    // Node* lowestCommonAncestor(Node* p, Node * q) {
    //     unordered_set<int> unique;
    //     while(p || q){
    //         if(p){
    //             if(unique.count(p->val)){
    //                 return p;
    //             }
    //             unique.insert(p->val);
    //             p=p->parent;
    //         }
    //         if(q){
    //             if(unique.count(q->val)){
    //                 return q;
    //             }
    //             unique.insert(q->val);
    //             q=q->parent;
    //         }
    //     }
    //     return nullptr;
    // }
   
};