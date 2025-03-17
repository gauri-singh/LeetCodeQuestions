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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        //let's imagine that root is (0,0) every left child is 
        if(!root){
            return {};
        }
        queue<pair<int,TreeNode*>> q;//x coordinate(column) & node
        unordered_map<int,vector<int>> map; // key column number, value : all node in the same column
        vector<vector<int>> res;
        q.push({0,root});
        int maxX=INT_MIN,minX=INT_MAX;
        while(!q.empty()){
            int x = q.front().first;
            TreeNode* node = q.front().second; 
            q.pop();
            map[x].push_back(node->val);
            minX=min(minX,x);
            maxX=max(maxX,x);
            if(node->left){
                q.push({x-1,node->left});
            }
             if(node->right){
                q.push({x+1,node->right});
            }
        }
        for(int i=minX;i<=maxX;i++){
            res.push_back(map[i]); // since we need to return in order from left to right
        }
        return res;
    }
};