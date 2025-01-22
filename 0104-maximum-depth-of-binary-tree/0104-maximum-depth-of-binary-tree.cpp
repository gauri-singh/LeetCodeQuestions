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
//DFS
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
//Iterative BFS
    // int maxDepth(TreeNode* root) {
    //     if(!root){
    //         return 0;
    //     }
    //     queue<TreeNode*> q;
    //     int levels=0;
    //     q.push(root);
    //     while(!q.empty()){
    //         int size = q.size();
    //         for(int i=0;i<size;i++){
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if(node->left) q.push(node->left);
    //             if(node->right) q.push(node->right);
    //         }
    //         levels++;
    //     }
    //     return levels;
    // }

    //Iterative DFS
    //  int maxDepth(TreeNode* root) {
    //     stack<pair<TreeNode*,int>> st; // pair of node and current depth
    //     st.push({root,1});
    //     int res=0;
    //     while(!st.empty()){
    //         TreeNode* node = st.top().first;
    //         int currDepth = st.top().second;
    //         st.pop();
    //         if(node){
    //             res= max(res,currDepth);
    //             st.push({node->left,currDepth+1});
    //             st.push({node->right,currDepth+1});
    //         }
    //     }
    //     return res;
    // }
};