/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct greater{
        bool operator ()(const ListNode* left, const ListNode* right){
            return left->val > right->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, greater> minHeap;
        
        for_each(lists.begin(), lists.end(), [&minHeap](ListNode* node){
            if (node != NULL){
                minHeap.push(node);                
            }
        });
        
        ListNode* head = NULL;
        ListNode* curNode = NULL;
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if (head == NULL){
                head = top;
                curNode = head;
            }else{
                curNode->next = top;
                curNode = curNode->next;
            }
            
            if (top->next != NULL){
                minHeap.push(top->next);
            }
        }
        
        return head;
    }
};
