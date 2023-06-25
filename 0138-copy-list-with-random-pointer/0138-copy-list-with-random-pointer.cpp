/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        
        // Step 1: Create new nodes and interweave them with the original list
        Node* ptr1 = head;
        Node* ptr2 = NULL;
        while(ptr1!=NULL){
            ptr2 = new Node(ptr1->val);
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr1->next->next;
        }
        
        // Step 2: Assign random pointers for the cloned nodes
        ptr1 = head;
        while(ptr1!=NULL){
            if(ptr1->random!=NULL){
                ptr1->next->random = ptr1->random->next;    
            }
            ptr1 = ptr1->next->next;
        }
        
        // Step 3: Separate the original and cloned lists
        ptr1 = head;
        ptr2 = head->next;
        Node* clonedHead = ptr2;
        while(ptr1!=NULL){
            ptr1->next = ptr2->next;
            if(ptr2->next!=NULL){
                ptr2->next = ptr2->next->next;    
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return clonedHead;
    }
};