/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseLinkList(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        
        ListNode* reversedHead = reverseLinkList(head->next);
        if (reversedHead){
            head->next->next = head;
            head->next = nullptr;
        }else{
            reversedHead = head;
        }

        return reversedHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tailInGroup = head;
        int count = k - 1;
        while(count > 0){
            tailInGroup = tailInGroup ? tailInGroup->next : tailInGroup;
            count--;
        }
        
        if (tailInGroup == nullptr){ //there are less that K node in this group
            return head;
        }
        
        ListNode* restReversed = reverseKGroup(tailInGroup->next, k);
        tailInGroup->next = nullptr;
        ListNode* reversedHead = reverseLinkList(head);
        head->next = restReversed;
        return reversedHead;
    }
};
