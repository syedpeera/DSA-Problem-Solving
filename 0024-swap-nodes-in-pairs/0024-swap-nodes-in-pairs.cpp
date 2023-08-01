/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        while(head != NULL && head->next != NULL){
            ListNode* first = head;
            ListNode* second = head->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            head = first->next;
        }
        return dummy->next;
    }
};