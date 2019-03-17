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
    void findLeftestNode(TreeNode* root, int& index){
        if (root == NULL){
            return;
        }
        
        int leftIndex = 0;
        findLeftestNode(root->left, leftIndex);
        
        int rightIndex = 0;
        findLeftestNode(root->right, rightIndex);
        
        index = max(leftIndex + 1, rightIndex - 1);

    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL){
            return result;
        }
        
        int mostLeftIndex = 0;
        findLeftestNode(root, mostLeftIndex);
        mostLeftIndex--;
        
        queue<pair<TreeNode*, int>> nodeQ;
        nodeQ.push(pair<TreeNode*, int>(root, mostLeftIndex));
        
        while(!nodeQ.empty()){
            pair<TreeNode*, int> nodeIndxpair = nodeQ.front();
            nodeQ.pop();
            
            while(result.size() < nodeIndxpair.second + 1){
                result.push_back(vector<int>());
            }
            
            result[nodeIndxpair.second].push_back(nodeIndxpair.first->val);
            
            if(nodeIndxpair.first->left){
                nodeQ.push(pair<TreeNode*, int>(nodeIndxpair.first->left, nodeIndxpair.second - 1));
            }
            
            if(nodeIndxpair.first->right){
                nodeQ.push(pair<TreeNode*, int>(nodeIndxpair.first->right, nodeIndxpair.second + 1));
            }
        }
        
        return result;
    }
};
