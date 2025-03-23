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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<vector<int>>>map;
       queue<pair<TreeNode*,int>> q;
       vector<vector<int>> res;
       int minX=INT_MAX,maxX=INT_MIN;
       q.push({root,0});// node, coordinate 
       int level=0;
       while(!q.empty()){
        int size=q.size();
        level++;
        for(int i=0;i<size;i++){
            TreeNode* node= q.front().first;
            int x= q.front().second; q.pop();
            map[x].push_back({level,node->val});// to sort based on level
            maxX=max(maxX,x);
            minX=min(minX,x);
            if(node->left){
                q.push({node->left,x-1});
            }
            if(node->right){
                q.push({node->right,x+1});
            }
        }
       }
       for(int i=minX;i<=maxX;i++){
        sort(map[i].begin(),map[i].end());
            vector<int> vec;// temporary variable to store the values and discard the levels
            for(auto it: map[i]){
                vec.push_back(it[1]);
            }
            res.push_back(vec);
       }
       return res;
    }
};