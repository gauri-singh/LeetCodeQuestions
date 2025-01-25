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
    bool isValidBST(TreeNode* root) {
     return isValid(root,LONG_MIN,LONG_MAX);
    }
private:
    bool isValid(TreeNode* node, long lowerBound, long upperBound){
        if(!node){
            return true;
        }

        if(!(lowerBound < node->val && node->val< upperBound)){
            //conditions of binary search tree not met for current node 
            return false;
        }
        //each subsequent left child is upper bounded by the parent's value 
        //& each subsequent right child is lowerbounded by the parent's value
        return isValid(node->left,lowerBound,node->val) &&
                isValid(node->right, node->val, upperBound);
        // we leave the lowerbound for left child and upperbound for right child as it is
        //in case the boundary was set in previous recurssions, for ex, left grandchild in right subtree so previous bounds will also hold
    }
};