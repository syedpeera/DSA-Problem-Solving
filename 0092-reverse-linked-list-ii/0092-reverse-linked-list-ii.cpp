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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *preLeft = dummy;
        
        for(int i=1; i<left; i++){
            preLeft = preLeft->next;
        }
        
        ListNode *prev = preLeft;
        ListNode *curr = preLeft->next;
        ListNode *next;
        for(int i=left; i<=right; i++){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        preLeft->next->next = curr;
        preLeft->next = prev;
        
        return dummy->next;
    }
};