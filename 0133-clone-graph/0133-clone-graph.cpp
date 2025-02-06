/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
map<Node*,Node*> oldToNew;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        return dfs_cloning(node);
    }
    Node* dfs_cloning(Node* node){
        if(oldToNew.count(node)){
            //already cloned
            return oldToNew[node];
        }
        //clone has to be created
        Node* copy = new Node(node->val); // new node created with old value
        oldToNew[node]=copy;
        //now recursively clone the neighbors 
        for(auto n: node->neighbors){
            copy->neighbors.push_back(dfs_cloning(n));
        }
        return oldToNew[node];
    }
};