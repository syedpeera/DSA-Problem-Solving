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
    bool isPalindrome(ListNode* head) {
        ListNode* firstHalfEnd = findFirstHalfEnd(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
        
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        
        bool isPalindrome = true;
        
        while(p2 != NULL){
            if(p1->val != p2->val){
                isPalindrome = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        firstHalfEnd->next = secondHalfStart;
        
        return isPalindrome;
    }
    
    ListNode* findFirstHalfEnd(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};