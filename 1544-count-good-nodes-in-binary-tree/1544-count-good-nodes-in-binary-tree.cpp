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
//  class Solution {
// public:
// int good=0;
//     int goodNodes(TreeNode* root) {
//         dfs(root,INT_MIN);
//         return good;
//     }
//     void dfs(TreeNode* root, int greatest){
//         if(!root){
//             return ;
//         }
//         if(root->val>=greatest){
//             greatest=root->val;
//             good++;
//         }
//         dfs(root->left,greatest);
//         dfs(root->right,greatest);
//     }
// };
//little optmization
class Solution {
public:
    int goodNodes(TreeNode* root) {
       return dfs(root,INT_MIN);
       
    }
    int dfs(TreeNode* root, int greatest){
        if(!root){
            return 0 ;
        }
        int res=0;
        if(root->val>=greatest){
            greatest=root->val;
            res++;
        } 
        //result = current good node + number of good nodes in left treee + number of good nodes in right tree
        res+= dfs(root->left,greatest) + dfs(root->right,greatest);
        return res;
    }
};