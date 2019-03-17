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
    TreeNode* deserializeHelper(stringstream& os){
        string rootValStr;
        os >> rootValStr;
        
        if (rootValStr == "#"){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(rootValStr));
        root->left = deserializeHelper(os);
        root->right = deserializeHelper(os);
        
        return root;
    }
public:

    // Encodes a tree to a single string.
    // pre-order traversal
    string serialize(TreeNode* root) {
        if (root == NULL){
            return "# ";
        }
        
        stringstream os;
        os << root->val << " ";
        os << serialize(root->left);
        os << serialize(root->right);
        
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream os(data);
        return deserializeHelper(os);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
