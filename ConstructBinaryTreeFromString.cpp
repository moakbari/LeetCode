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
    string readTilParen(string& s, int& i){
        string output;
        while(i < s.size() && s[i] != '(' && s[i] != ')')
        {
            output.push_back(s[i]);
            i++;
        }
              
        return output;
    }
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode*> nodeStack;
        int i = 0;
        while(i < s.size()){
            if (s[i] == ')'){
                TreeNode* child = nodeStack.top();
                nodeStack.pop();
                TreeNode* parent = nodeStack.top();
                nodeStack.pop();
                
                if (parent->left == nullptr){
                    parent->left = child;
                }else{
                    parent->right  = child;
                }
                nodeStack.push(parent);
                i++;
            }else if (s[i] == '('){
                i++;   
            }
            else{
                string nodeval = readTilParen(s, i);
                TreeNode* node = new TreeNode(stoi(nodeval));
                nodeStack.push(node);
            }
        }
        
        return nodeStack.empty() ? nullptr : nodeStack.top();
    }
};
