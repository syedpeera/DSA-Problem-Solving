/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head==null){
            return null;
        }

        // Step 1: Create new nodes and interweave them with the original list
        Node ptr1 = head;
        Node ptr2 = null;
        while(ptr1!=null){
            ptr2 = new Node(ptr1.val);
            ptr2.next = ptr1.next;
            ptr1.next = ptr2;
            ptr1 = ptr1.next.next;
        }
        
        // Step 2: Assign random pointers for the cloned nodes
        ptr1 = head;
        while(ptr1!=null){
            if(ptr1.random!=null){
                ptr1.next.random = ptr1.random.next;
            }
            ptr1 = ptr1.next.next;
        }
        
        // Step 3: Separate the original and cloned lists
        ptr1 = head;
        ptr2 = head.next;
        Node clonedHead = head.next;
        
        while(ptr1!=null){
            ptr1.next = ptr2.next;
            
            if(ptr2.next!=null){
                ptr2.next = ptr2.next.next;
            }
            
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }
        return clonedHead;
    }
}