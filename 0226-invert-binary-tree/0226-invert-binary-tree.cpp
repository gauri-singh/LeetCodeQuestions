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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        //switch the nodes;
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
         swap(root->left,root->right);
        //call the function to recursively switch children nodes
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};