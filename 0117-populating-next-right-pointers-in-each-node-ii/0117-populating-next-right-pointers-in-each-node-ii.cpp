/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        unordered_map<int,vector<Node*>> levelMap;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                Node* node =q.front();
                q.pop();
                if(node){
                    levelMap[level].push_back(node);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            level++;
        }
        for(auto [level, levelNodes] : levelMap){
            Node* prev =levelNodes[0];
            for(int i=1;i<levelNodes.size();i++){
                prev->next=levelNodes[i];
                prev=levelNodes[i];
            }
            prev->next=nullptr;
        }
        return root;
    }
};