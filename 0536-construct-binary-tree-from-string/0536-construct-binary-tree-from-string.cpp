/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*> st;
        int i=0;
        while(i<s.length()){
            if(s[i]==')'){
                i++;
                st.pop(); // End of the current node's subtree; pop from the stack.

            }
            else if(s[i]=='('){
                i++;
            }
            else{
                //Parse the number (could be negative)
                int sign =1;
                if(s[i]=='-'){
                    sign=-1;
                    i++;
                }
                string num="";
                while(isdigit(s[i])){
                    num+=s[i];
                    i++;
                }
                TreeNode* node=new TreeNode(sign*stoi(num));// create node with the value;
                if(!st.empty()){
                //If there's a node in the stack, attach the new node to it.
                TreeNode*  parent=st.top();
                    if(!parent->left){
                        parent->left=node;
                    }else{
                        parent->right=node;
                    }
                }
                //push current node to the stack
                st.push(node);
            }
        }
        if(!st.empty()) return st.top();
        return nullptr;
    }
};