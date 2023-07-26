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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = head;
        int count = 0;
        
        //count the number of nodes
        while(head != nullptr){
            head = head->next;
            count++;
        }
        
        while(count >= k){
            curr = prev->next;
            next = curr->next;
            for(int i=1; i<k; i++){
                curr->next = next->next;
                next->next = prev->next;
                
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count = count - k;
        }
        return dummy->next;
    }
};