//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    static Node* reverseLinkedList(struct Node* head){
        struct Node* prev = NULL;
        struct Node* curr = head;
        struct Node* next = head;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseLinkedList(first);
        second = reverseLinkedList(second);
        struct Node* l1 = first;
        struct Node* l2 = second;
        
        struct Node* l3 = new Node(0);
        int carry = 0;
        struct Node* dummy = l3;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->data + l2->data + carry;
            carry = sum/10;
            l3->next = new Node(sum%10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->data + carry;
            carry = sum/10;
            l3->next = new Node(sum%10);
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = l2->data + carry;
            carry = sum/10;
            l3->next = new Node(sum%10);
            l3 = l3->next;
            l2 = l2->next;
        }
        if(carry>0){
            l3->next = new Node(carry);
        }
        struct Node* head = dummy->next;
        dummy->next = NULL;
        delete dummy;
        head = reverseLinkedList(head);
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends