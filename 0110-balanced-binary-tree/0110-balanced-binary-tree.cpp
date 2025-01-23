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
 //shortcircuiting as soon as we find unbalanced subtree
 class Solution{
    public:
    bool isBalanced(TreeNode* root){
        return findHeight(root)!=-1;  //if -1 it is unbalanced tree
    }
    int findHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        // If any subtree is already unbalanced, short-circuit by returning -1
        if(left==-1 ||right ==-1 || abs(left-right)>1){
            return -1;
        }
        return 1+max(left,right);
    }
 };
 //regular dfs
// class Solution {
// public:
// bool res=true;
//     bool isBalanced(TreeNode* root) {
//         findHeight(root);
//         return res;
//     }
//     int findHeight(TreeNode* root){
//         if(!root){
//             return 0;
//         }
//         int left = findHeight(root->left);
//         int right = findHeight(root->right);
//         if(abs(left-right)>1){
//             res=false;
//             return -1;
//         }
//         return 1+max(left,right);
//     }
// };