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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* ptr1 = dummy;
        ListNode* ptr2 = dummy;
        
        for(int i=0;i<=n;i++){
            ptr1=ptr1->next;
        }
        while(ptr1!=NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ListNode* toDelete = ptr2->next;
        ptr2->next = ptr2->next->next;
        
        delete toDelete;
        
        return dummy->next;
    }
};