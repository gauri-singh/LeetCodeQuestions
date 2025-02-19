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
vector<int> boundary;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return boundary;
        }
        boundary.push_back(root->val);
        isLeftBoundary(root->left);
        leaves(root->left);
        leaves(root->right);
        isRightBoundary(root->right);
        return boundary;
    }
    void leaves(TreeNode* root){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            // leaf node found
            boundary.push_back(root->val);
            return;
        }
        //check for leaves in both subtrees
        leaves(root->left);
        leaves(root->right);
    }
    void isLeftBoundary(TreeNode* root){
        if(!root || ( !root->left && !root->right)){
            //should have atleast one child to proceed else leaf node so return
            return;
        }
        // current node is in left
        boundary.push_back(root->val);
        if(root->left == nullptr){   
            //check if right child could be the left boundary
            isLeftBoundary(root->right);
        }
        else{
             //check if left child could be the left boundary
            isLeftBoundary(root->left);
        }
    }
      void isRightBoundary(TreeNode* root){
        if(!root || ( !root->left && !root->right)){
            //should have atleast one child to proceed else leaf node so return
            return;
        }
      
        if(root->right == nullptr){   
            //check if left child could be the right boundary
            isRightBoundary(root->left);
        }
        else{
             //check if left child could be the right boundary
        isRightBoundary(root->right);
        }
        // current node is in right boundary
        boundary.push_back(root->val);
    }
};