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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*,vector<TreeNode*>> adjMap;
      if(k==0){
        return {target->val};
        } 
        TreeNode* curr= root;
        //poppulating adjacency list
      queue<TreeNode*> graph;
      graph.push(root);
      while(!graph.empty()){
        TreeNode* curr =graph.front();
        graph.pop();
        if(curr && curr->left){
            adjMap[curr].push_back(curr->left);
            adjMap[curr->left].push_back(curr);// adding parent to the adjacency list of child node
            graph.push(curr->left);
        }
        
        if(curr && curr->right){
            adjMap[curr].push_back(curr->right);
            adjMap[curr->right].push_back(curr);// adding parent to the adjacency list of child node
            graph.push(curr->right);
        }
      }

      vector<int> res;
      visited.insert(target);
      queue<pair<TreeNode*,int>>q;
      q.push({target,0});
      while(!q.empty()){
        TreeNode* curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dist==k  && curr){
            res.push_back(curr->val);
        }
        else{
            for(auto next : adjMap[curr]){
                if(!visited.count(next)){
                    visited.insert(next);
                    q.push({next,dist+1}); // add all the neighbours from curren node to the queue for processing
                }
            }
        }
      }
        return res;
    }
};