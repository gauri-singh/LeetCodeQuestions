/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
//DFS : recursive
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!p || !q || !root){
    //         return nullptr;
    //     }

    //     if(max(p->val,q->val) < root->val){
    //         //if the maximum of both is less, then both are less and in left subtree
    //        return lowestCommonAncestor(root->left,p, q);
    //     }
    //     else if(min(p->val,q->val) > root->val){
    //         //if the minimum of both is greater, then both are greater and in right subtree
    //        return lowestCommonAncestor(root->right,p, q);
    //     }
    //     else{
    //         return root; // if p and q are in seperate sub trees or if one of them is root. combining both these cases by using else
    //     }
    // }

//iterative way
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr =root;
        while(curr){
            if(min(p->val,q->val)> curr->val){
                //if the minimum of both is greater, then both are greater and in right subtree
                curr=curr->right;
            }
            else if(max(p->val,q->val)< curr->val){
                //if the maximum of both is less, then both are less and in left subtree
                curr=curr->left;
            }
            else{
                return curr;
                // if p and q are in seperate sub trees or if one of them is root. combining both these cases by using else
            }
        }
        return nullptr;
    }
};