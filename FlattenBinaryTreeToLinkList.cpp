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
    TreeNode* flattenHelper(TreeNode* root){
        if (root == nullptr){
            return nullptr;
        }
        
        TreeNode* leftTail = flattenHelper(root->left);
        TreeNode* rightTail = flattenHelper(root->right);

        
        TreeNode* rightHead = root->right;
        TreeNode* leftHead = root->left;
        
        root->left = nullptr;
        
        if (leftHead != nullptr){
            root->right = leftHead;
            leftTail->right = rightHead;
        }
        
        if (rightTail == nullptr){
            rightTail = leftTail ? leftTail : root;
        }
        
        return rightTail;
    }
    
    
    void flatten(TreeNode* root) {
        
        flattenHelper(root);
     }
};
