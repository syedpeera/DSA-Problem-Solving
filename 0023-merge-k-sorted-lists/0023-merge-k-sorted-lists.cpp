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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(ListNode* element: lists){
            if(element!=NULL){
                minHeap.push(element);
            }
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            minHeap.pop();
            if(head==NULL){
                head=curr;
                tail=curr;
            }
            else{
                tail->next=curr;
                tail=curr;
            }
            if(curr->next!=NULL){
                minHeap.push(curr->next);
            }
        }
        return head;
    }
};