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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null){
            return true;
        }
        
        ListNode firstHalfEnd = findFirstHalfEnd(head);
        ListNode secondHalfStart = reverseList(firstHalfEnd);
        
        ListNode p1 = head;
        ListNode p2 = secondHalfStart;
        
        boolean isPalindrome = true;
        
        while(p2 != null){
            if(p1.val != p2.val){
                isPalindrome = false;
                break;
            }
            p1 = p1.next;
            p2 = p2.next;
        }
        
        return isPalindrome;
    }
    
    ListNode findFirstHalfEnd(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow;
    }
    
    ListNode reverseList(ListNode head){
        ListNode prev = null;
        ListNode curr = head;
        ListNode next = null;
        
        while(curr != null){
            next = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
}