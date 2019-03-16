/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL){
            return NULL;
        }
        
        Node* leftHead = treeToDoublyList(root->left);
        Node* rightHead = treeToDoublyList(root->right);
        
        Node* finalHead = NULL;
        
        if (leftHead != NULL){
            finalHead = leftHead;
            finalHead->left->right = root;
            root->left = finalHead->left;
            
        }else{
            finalHead = root;
        }
        
        Node* finalTail = NULL;
        
        if(rightHead != NULL){
            finalTail = rightHead->left;
            root->right = rightHead;
            rightHead->left = root;
        }else{
            finalTail = root;
        }
        
        finalTail->right = finalHead;
        finalHead->left = finalTail;
        
        return finalHead;
    }
};
