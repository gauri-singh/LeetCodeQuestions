/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode="";
        dfsEncode(root,encode);
        return encode;
    }

    void dfsEncode(TreeNode* node, string &encode){
        if(!node){
            encode+="N,";
            return; //for null pointer we are doing custom encoding
        }
        encode+=to_string(node->val)+","; // adding delimiter to seperate the multiple digit values
        dfsEncode(node->left,encode);
        dfsEncode(node->right,encode);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;
        int itr=0;
        stringstream ss(data);// to remove delimiters
        string token; // to store each value
        while(getline(ss,token,',')){
            arr.push_back(token);
        }
        return dfsDecode(arr,itr);
    }

    TreeNode* dfsDecode(vector<string>& arr, int& itr){
        if(arr[itr]=="N"){
            itr++; // move iterator forward
            return nullptr; //null node
        }
        TreeNode* root = new TreeNode(stoi(arr[itr]));
        itr++; // move pointer forward
        root->left=dfsDecode(arr,itr); 
        root->right=dfsDecode(arr,itr);
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));