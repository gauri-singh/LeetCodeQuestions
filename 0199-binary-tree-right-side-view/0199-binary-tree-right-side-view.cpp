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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* rightElement;
        vector <int> ans;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            rightElement= nullptr;
            int size = q.size(); // size of current level
            for(int i=0;i<size;i++){
                TreeNode* node = q.front(); // get the element
                q.pop();
                if(node){
                    rightElement = node; //keep updating for each node and the last one would be the right side element of that level
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(rightElement){
                //push to result
                ans.push_back(rightElement->val);
            }
        }
        return ans;
    }
};