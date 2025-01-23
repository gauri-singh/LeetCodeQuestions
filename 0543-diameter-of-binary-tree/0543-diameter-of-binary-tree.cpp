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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findHeight(root,diameter);
        return diameter;
    }
private:
    int findHeight(TreeNode* root, int & diameter){
        //diameter could also be declared as global variable instead of makign private function and ussing call by reference

        if(!root){
            return 0;
        }
        int left = findHeight(root->left,diameter);
        int right = findHeight(root->right,diameter);

        diameter= max(diameter,left+right); // the diameter at any node is sum of the height of left subtree and the height of right subtree
        return 1+max(left,right); // return height of current node : height of taller child+1 for current node
    }
};