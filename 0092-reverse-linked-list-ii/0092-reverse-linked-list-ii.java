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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left == right || head == null || head.next == null){
            return head;
        }
        
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        ListNode preLeft = dummy;
        for(int i=1; i<left; i++){
            preLeft = preLeft.next;
        }
        
        ListNode prev = preLeft;
        ListNode curr = preLeft.next;
        ListNode next;
        
        for(int i=left; i<=right; i++){
            next = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = next;
        }
        
        preLeft.next.next = curr;
        preLeft.next = prev;
        
        return dummy.next;
    }
}