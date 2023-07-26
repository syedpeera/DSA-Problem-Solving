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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        ListNode prev = dummy;
        ListNode curr = head;
        ListNode next = head;
        int count = 0;
        
        //count number of nodes
        while(head != null){
            head = head.next;
            count++;
        }
        
        while(count >= k){
            curr = prev.next;
            next = curr.next;
            for(int i=1; i<k; i++){
                curr.next = next.next;
                next.next = prev.next;
                
                prev.next = next;
                next = curr.next;
            }
            
            prev = curr;
            count = count - k;
        }
        return dummy.next;
    }
}