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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]); // preorder[0] will always be the root
        //find this root value in the inorder array, since it is the mid point dividing the array into left and right subtree
        auto mid = find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        //mid also helps in deciding the size of the left subtree ( since 0 till mid is left subtree, as mid is the root )

        vector<int> leftPre (preorder.begin()+1,preorder.begin()+mid+1); // left subtree ( from 0 till mid+1 ( which is size of the left subtree))
        vector<int> rightPre (preorder.begin()+mid+1,preorder.end());

        vector<int> leftIn (inorder.begin(),inorder.begin()+mid); //left subtree : 0th till mid excluding mid(which is root) 
        vector<int> rightIn (inorder.begin()+mid+1,inorder.end()); // right subtree : mid+1 excluding mid(which is root) till end 

        root->left = buildTree(leftPre,leftIn);
        root->right =buildTree(rightPre,rightIn);

        return root;
    }
};