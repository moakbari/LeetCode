/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
1->2
5->4->3

1->5->2
4->3

*/
class Solution {
    ListNode* reverseLinkList(ListNode* head){
        if (head == NULL){
            return head;
        }
        
        ListNode* rest = reverseLinkList(head->next);
        
        if (head->next){
            head->next->next = head;
        }
        
        head->next = NULL;
        return rest ? rest : head;
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL){
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if (fast != NULL){
            prev = slow;
            slow = slow->next;
        }
        
        if(prev != NULL){
            prev->next = NULL;
        }
      
        slow = reverseLinkList(slow);
        ListNode* curNode = slow;

        ListNode* first = head;
        while(first != NULL && slow != NULL){
            ListNode* firstnext = first->next;
            ListNode* secondnext = slow->next;
            
            first->next = slow;
            slow->next = firstnext;
            
            first = firstnext;
            slow = secondnext;
        }
        
    }
};
