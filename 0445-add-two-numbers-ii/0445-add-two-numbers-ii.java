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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        
        while(l1 != null){
            s1.add(l1.val);
            l1 = l1.next;
        }
        
        while(l2 != null){
            s2.add(l2.val);
            l2 = l2.next;
        }
        
        int carry = 0;
        ListNode head = null;
        while(!s1.isEmpty() || !s2.isEmpty() || carry > 0){
            int sum = carry;
            
            if(!s1.isEmpty()){
                sum = sum + s1.pop();
            }
            
            if(!s2.isEmpty()){
                sum = sum + s2.pop();
            }
            
            carry = sum / 10;
            ListNode newNode = new ListNode(sum % 10);
            newNode.next = head;
            head = newNode;
        }
        return head;
    }
}