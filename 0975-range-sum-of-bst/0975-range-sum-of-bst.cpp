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
int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return sum;
    }
    void dfs(TreeNode* root, int low, int high) {
        if (!root) return; // Base case: if the node is null, return

        // If the current node's value is within the range [low, high], add it to the sum
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        // we are doing these checks because of = case. 
        // If the current node's value is greater than 'low', explore the left subtree.
        // This is because nodes in the left subtree will have smaller values.
        if (root->val > low) {
            dfs(root->left, low, high);
        }

        // If the current node's value is less than 'high', explore the right subtree.
        // This is because nodes in the right subtree will have larger values.
        if (root->val < high) {
            dfs(root->right, low, high);
        }
    }
};