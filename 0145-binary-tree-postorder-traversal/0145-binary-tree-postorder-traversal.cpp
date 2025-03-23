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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        vector<int> res;
        st.push(root);
        //preorder = Node,Left,Right // postorder = Left,Right,Node;
        //preorder hacked to make postorder easy-> we need to reverse 
        // so do different pre-order: Node, Right, Left, =>>> so when it is reversed it becomes post orderrrr :))))))!!!!!!!!!!!!!!!!!!!!!
        while(!st.empty()){
            root=st.top();st.pop();
            if(root){
                res.push_back(root->val);
                st.push(root->left);
                st.push(root->right);
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};