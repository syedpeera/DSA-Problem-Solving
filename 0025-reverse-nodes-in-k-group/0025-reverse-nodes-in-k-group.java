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
        ListNode prev = null;
        ListNode curr = head;
        ListNode next = head;
        int count = 0;
        
        while(curr != null && count < k){
            curr = curr.next;
            count++;
        }
        
        if(count == k){
            curr = head;
            for(int i=0; i<k; i++){
                next = curr.next;
                curr.next = prev;
                
                prev = curr;
                curr = next;
            }
            
            if(next != null){
                head.next = reverseKGroup(next, k);
            }
            
            head = prev;
        }
        return head;
    }
}