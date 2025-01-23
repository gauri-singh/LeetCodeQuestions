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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot){
            //either reached end without a problem or nulltree which will automatically be a subtree
            return true;
        }
        if(!root){
            //subRoot exists but root doesn't
            return false;
        }
        if(isIdenticalTree(root,subRoot)){
            return true; // they are same trees
        }
        //check if either of the left or right children could be a match 
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isIdenticalTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true; //have reached end of both trees without mismatch
        }
        if(root && subRoot && root->val == subRoot->val){
            //these current nodes match now lets compare their children
            return isIdenticalTree(root->left,subRoot->left) && isIdenticalTree(root->right,subRoot->right);
            //return true only if both trees have same left and right subtrees
        }
        return false;
    }
};