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
    pair<int, int> maxPathSumHelper(TreeNode* root){

        if (root->left == NULL && root->right == NULL){
            cout << root->val << ", " << root->val << endl;
            return pair<int, int>(root->val,root->val);
        }
        
        
        int maxEndAtNode = numeric_limits<int>::min();
        int maxNotEndAtNode = numeric_limits<int>::min();
        int pathLengthPassingRoot = root->val;
        if (root->left != NULL){
            pair<int,int> leftRes = maxPathSumHelper(root->left);
            maxEndAtNode = max(maxEndAtNode, leftRes.first);
            maxNotEndAtNode = max(maxNotEndAtNode, leftRes.second);
            pathLengthPassingRoot = leftRes.first > 0 ? pathLengthPassingRoot + leftRes.first : pathLengthPassingRoot;
        }
        
        if (root->right != NULL){
            pair<int,int> rightRes = maxPathSumHelper(root->right);
            maxEndAtNode = max(maxEndAtNode, rightRes.first);
            maxNotEndAtNode = max(maxNotEndAtNode, rightRes.second);
            pathLengthPassingRoot =  rightRes.first > 0 ? pathLengthPassingRoot + rightRes.first : pathLengthPassingRoot;
        }
        
        
        
        pair<int,int> res;
        res.first = maxEndAtNode > 0 ? maxEndAtNode + root->val : root->val;
        res.second = max(max(pathLengthPassingRoot, maxNotEndAtNode), res.first);

        return res;
        
    }
public:
    int maxPathSum(TreeNode* root) {
        pair<int, int> res = maxPathSumHelper(root);
        
        return res.second;

    }
};
