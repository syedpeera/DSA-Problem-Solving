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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;
            }
            else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = (left != nullptr)? left: right;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr ||  head->next == nullptr){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);
        
        return merge(left, right);
    }
};