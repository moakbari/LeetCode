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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr){
            return result;
        }
        
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        int count = nodeQ.size();
        
        while(!nodeQ.empty()){
            TreeNode* curNode = nodeQ.front();
            nodeQ.pop();
            
            if(curNode->left){
                nodeQ.push(curNode->left);
            }
            
            if (curNode->right){
                nodeQ.push(curNode->right);
            }
            
            count--;
            if(count == 0){
                result.push_back(curNode->val);
                count = nodeQ.size();
            }
        }
        
        return result;
    }
};
