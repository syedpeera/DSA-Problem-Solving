/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        if(head==null || head.next==null){
            return;
        }
        
        //Step 1: Find the middle of the list
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        //Step 2: Reverse the second half of the list
        ListNode next = null;
        ListNode prev = null;
        ListNode curr = slow.next;
        slow.next = null;
        
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = next;
        }
        
        //Step 3: Merge the two halves by alternating nodes
        ListNode ptr1 = head;
        ListNode ptr2 = prev;
        
        while(ptr2!=null){
            ListNode firstNext = ptr1.next;
            ListNode secondNext = ptr2.next;
            
            ptr1.next = ptr2;
            ptr2.next = firstNext;
            
            ptr1 = firstNext;
            ptr2 = secondNext;
        }
    }
}