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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        dfs(root,res);
        return res;
    }

    int dfs(TreeNode* root, int& res){
        if(!root){
            return 0;
        }
  // Use max(0, dfs(...)) to ignore negative contributions (negative values decrease the path sum
        int leftMax= max(0,dfs(root->left,res)); 
        int rightMax= max(0,dfs(root->right,res)); 
        
        // Update the result (res) to reflect the maximum path sum considering the current node
        // The current node acts as the "root" of the path that includes both left and right subtrees
        res = max(res, root->val + leftMax + rightMax);

        // Return the maximum sum path that can be extended to the parent node
        // This is the node's value plus the greater of its left or right subtree contributions
        return (root->val + max(leftMax, rightMax));}
};