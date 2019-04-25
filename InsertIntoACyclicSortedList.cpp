/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if (head == nullptr){
            newNode->next = newNode;
            return newNode;
        }
        
        /* 4 cases for adding the new node
        1- new value is between two already existing node
        2- new value is greater than the last node
        3- new value is smaller than the first node
        4- new value is equal to a node

        */
        
        Node* curNode = head;
        do{
            if ((insertVal > curNode->val && 
                (insertVal < curNode->next->val || curNode->next->val < curNode->val))
                || (curNode->next->val < curNode->val && insertVal < curNode->next->val)
                || insertVal == curNode->val) 
            {
                newNode->next = curNode->next;
                curNode->next = newNode;
                return head;
            }
            
            curNode = curNode->next;
        }while(curNode != head);
                
        //corner case: all list nodes have same value.
        newNode->next = curNode->next;
        curNode->next = newNode;
        return head;
    }
};
