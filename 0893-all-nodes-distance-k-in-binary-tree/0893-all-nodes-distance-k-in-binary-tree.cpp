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
        // To keep track of visited nodes during BFS
        unordered_set<TreeNode*> visited;

        // Adjacency map to store the graph representation of the tree
        // Key: TreeNode*, Value: List of neighboring nodes (left, right, and parent)
        unordered_map<TreeNode*, vector<TreeNode*>> adjMap;

        // If k is 0, the result is just the target node itself
        if (k == 0) {
            return {target->val};
        }

        // Populate the adjacency list using BFS
        queue<TreeNode*> graph;
        graph.push(root); // Start from the root
        while (!graph.empty()) {
            TreeNode* curr = graph.front();
            graph.pop();

            // Add left child to the adjacency list
            if (curr && curr->left) {
                adjMap[curr].push_back(curr->left); // Add child to parent's list
                adjMap[curr->left].push_back(curr); // Add parent to child's list
                graph.push(curr->left); // Process left child
            }

            // Add right child to the adjacency list
            if (curr && curr->right) {
                adjMap[curr].push_back(curr->right); // Add child to parent's list
                adjMap[curr->right].push_back(curr); // Add parent to child's list
                graph.push(curr->right); // Process right child
            }
        }

        // Result vector to store nodes at distance k from the target
        vector<int> res;

        // Mark the target node as visited
        visited.insert(target);

        // Queue for BFS: stores pairs of (current node, distance from target)
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0}); // Start BFS from the target node with distance 0

        // Perform BFS to find all nodes at distance k
        while (!q.empty()) {
            TreeNode* curr = q.front().first; // Current node
            int dist = q.front().second; // Distance of current node from the target
            q.pop();

            // If the current node is at distance k, add it to the result
            if (dist == k && curr) {
                res.push_back(curr->val);
            } 
            // Otherwise, explore its neighbors
            else {
                for (auto next : adjMap[curr]) {
                    // If the neighbor hasn't been visited, process it
                    if (!visited.count(next)) {
                        visited.insert(next); // Mark as visited
                        q.push({next, dist + 1}); // Add to queue with incremented distance
                    }
                }
            }
        }

        // Return the result
        return res;
    }
};