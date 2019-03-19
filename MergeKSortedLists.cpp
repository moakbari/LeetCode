/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    using PairType = pair<int, int>;
    struct greater{
        bool operator()(const PairType& left, const PairType& right){
            return left.first > right.first;
        }
    };    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<PairType, vector<PairType>, greater> minHeap;
        
        int j = 0;
        for_each(lists.begin(), lists.end(), [&minHeap, j](ListNode* node) mutable -> void {
            if (node != NULL){
                minHeap.push(PairType(node->val, j));                
            }
            j++;
        });
        
        ListNode* head = NULL;
        ListNode* curNode = NULL;
        while(!minHeap.empty()){
            PairType top = minHeap.top();
            minHeap.pop();
            if (head == NULL){
                head = lists[top.second];
                curNode = head;
            }else{
                curNode->next = lists[top.second];
                curNode = curNode->next;
            }
            
            if (lists[top.second]->next != NULL){
                lists[top.second] = lists[top.second]->next;
                minHeap.push(PairType(lists[top.second]->val, top.second));
            }
        }
        
        return head;
    }
};
