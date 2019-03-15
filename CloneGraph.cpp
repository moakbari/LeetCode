/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> copyNodes_;
    
    Node* cloneGraphHelper(Node* node){
        if (node == NULL){
            return node;
        }
        
        if (copyNodes_.find(node) != copyNodes_.end()){
            return copyNodes_[node];
        }
        
        Node* copiedNode = new Node();
        copyNodes_[node] = copiedNode;
        copiedNode->val = node->val;
        
        for(Node* childNode : node->neighbors){
            copiedNode->neighbors.push_back(cloneGraphHelper(childNode));
        }
        
        return copiedNode;
    }
    
public:
    Node* cloneGraph(Node* node) {
        return cloneGraphHelper(node);
    }
};
