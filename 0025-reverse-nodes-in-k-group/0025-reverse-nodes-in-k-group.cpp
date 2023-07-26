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
        if(head == nullptr){
            return nullptr;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head;
        int count = 0;
        
        while(curr != nullptr && count < k){
            curr = curr->next;
            count++;
        }
        
        if(count == k){
            curr = head;
            for(int i=0; i<k; i++){
                next = curr->next;
                curr->next = prev;
                
                prev = curr;
                curr = next;
            }
            
            if(next != nullptr){
                head->next = reverseKGroup(next, k);
            }
            
            head = prev;
        }
        
        return head;
    }
};