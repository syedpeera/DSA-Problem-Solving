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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        
        //Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Step 2: Reverse the second half of the list
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        //Step 3: Merge the two halves by alternating nodes
        ListNode* ptr1 = head;
        ListNode* ptr2 = prev;
        
        while(ptr2!=NULL){
            ListNode* firstNext = ptr1->next;
            ListNode* secondNext = ptr2->next;
            
            ptr1->next = ptr2;
            ptr2->next = firstNext;
            
            ptr1 = firstNext;
            ptr2 = secondNext;
        }
    }
};