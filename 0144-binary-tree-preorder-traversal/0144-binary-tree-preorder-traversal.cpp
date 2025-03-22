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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            if(root){
                res.push_back(root->val);
                st.push(root->right); // can add the if null checks here but this handles it anyway
                st.push(root->left);
            }
        }
        return res;
    }
};