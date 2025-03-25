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
int res=INT_MAX;
double diff=DBL_MAX;
    int closestValue(TreeNode* root, double target) {
        dfs(root,target);
        return res;
    }
    void dfs(TreeNode* root, double target){
        if(!root){
            return;
        }
        if(abs(target-root->val)<diff){
            diff=abs(target-root->val);
            res=root->val;
        }else if(abs(target-root->val)==diff){
            res=min(res,root->val);
        }
        if(target<root->val){
            dfs(root->left,target);
        }
        if(target>root->val){
            dfs(root->right,target);
        }
    }
};