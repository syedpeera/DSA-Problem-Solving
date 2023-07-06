//{ Driver Code Starts
// driver

import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG{
    
    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            
            int n = sc.nextInt();
            int val = sc.nextInt();
            
            Node first = new Node(val);
            Node tail = first;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            int m = sc.nextInt();
            val = sc.nextInt();
            
            Node second = new Node(val);
            tail = second;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            Solution g = new Solution();
            Node res = g.addTwoLists(first, second);
            printList(res);
        }
    }
}

// } Driver Code Ends


/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
    static Node reverseLinkedList(Node head){
        Node prev = null;
        Node curr = head;
        Node next = head;
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
    static Node addTwoLists(Node first, Node second){
        first = reverseLinkedList(first);
        second = reverseLinkedList(second);
        Node l1 = first;
        Node l2 = second;
        
        Node l3 = new Node(0);
        int carry = 0;
        Node dummy = l3;
        while(l1!=null && l2!=null){
            int sum = l1.data + l2.data + carry;
            carry = sum/10;
            l3.next = new Node(sum%10);
            l3 = l3.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int sum = l1.data + carry;
            carry = sum/10;
            l3.next = new Node(sum%10);
            l3 = l3.next;
            l1 = l1.next;
        }
        while(l2!=null){
            int sum = l2.data + carry;
            carry = sum/10;
            l3.next = new Node(sum%10);
            l3 = l3.next;
            l2 = l2.next;
        }
        if(carry>0){
            l3.next = new Node(carry);
        }
        Node head = dummy.next;
        dummy.next = null;
        head = reverseLinkedList(head);
        return head;
    }
}