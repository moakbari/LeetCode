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
    void findNodesToTarget(TreeNode* root, TreeNode* target, stack<TreeNode*>& nodesToTarget, bool& targetFound){
        if (root == nullptr || targetFound){
            return;
        }
        
        nodesToTarget.push(root);
        
        if (root == target){
            targetFound = true;
        }
        
        
        findNodesToTarget(root->left, target, nodesToTarget, targetFound);
        findNodesToTarget(root->right, target, nodesToTarget, targetFound);
        
        if(!targetFound){
            nodesToTarget.pop();
        }
    }
    
    void findNodesAtKDistance(TreeNode* node, TreeNode* nodeToAvoid, int K, vector<int>& listOfNodes){
        if (node == nullptr || node == nodeToAvoid){
            return;
        }
        
        if (K == 0){
            listOfNodes.push_back(node->val);
            return;
        }
        
        findNodesAtKDistance(node->left, nodeToAvoid, K - 1, listOfNodes);
        findNodesAtKDistance(node->right, nodeToAvoid, K - 1, listOfNodes);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        stack<TreeNode*> nodesToTarget;
        bool targetFound = false;
        findNodesToTarget(root, target, nodesToTarget, targetFound);
 
        
        TreeNode* nodeToAvoid = nullptr;
        vector<int> listOfNodes;
        while(!nodesToTarget.empty() && K >= 0) {
            findNodesAtKDistance(nodesToTarget.top(), nodeToAvoid, K, listOfNodes);
            nodeToAvoid = nodesToTarget.top();
            nodesToTarget.pop();
            K--;
        }
        
        return listOfNodes;
    }
};
