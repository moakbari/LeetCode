/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> nodeStack_;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* node = root;
        while (node != NULL){
            nodeStack_.push(node);
            node = node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = nodeStack_.top();
        nodeStack_.pop();
        int reVal = node->val;
        
        node = node->right;
        while(node){
            nodeStack_.push(node);
            node = node->left;
        }
        
        return reVal;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
