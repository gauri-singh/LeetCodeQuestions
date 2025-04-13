/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
int result=0;
    int diameter(Node* root) {
        getHeight(root);
        return result;
    }
    int getHeight(Node* node){
        if(!node){
            return 0;
        }
        //we only need heights of 2 longest subtrees
        int maxHeight=0,secondMaxHeight=0;
        for(auto child : node->children){
            int height=getHeight(child);
            if(height>maxHeight){
                secondMaxHeight=maxHeight;
                maxHeight=height;
            }else if(height>secondMaxHeight){
                secondMaxHeight=height;
            }
        }
        result=max(result,secondMaxHeight+maxHeight);
        return 1+maxHeight;
    }
};