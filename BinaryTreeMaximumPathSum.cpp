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
    int maxPathSumHelper(TreeNode* root, int& maxPathOverall){
        if(root == NULL){
            return 0;
        }

        int maxPathEndAtLeft = max(0, maxPathSumHelper(root->left, maxPathOverall));
        int maxPathEndAtRight = max(0, maxPathSumHelper(root->right, maxPathOverall));
        
        maxPathOverall = max(maxPathOverall, maxPathEndAtLeft + root->val +maxPathEndAtRight);
        
        return max(maxPathEndAtLeft + root->val , maxPathEndAtRight + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPathOverall = numeric_limits<int>::min();
        int maxPthEndAtRoot = maxPathSumHelper(root, maxPathOverall);
        
        return maxPathOverall;

    }
};
