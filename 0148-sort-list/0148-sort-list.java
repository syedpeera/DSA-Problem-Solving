class Solution {
    public ListNode merge(ListNode left, ListNode right){
        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;
        
        while(left != null && right != null){
            if(left.val < right.val){
                curr.next = left;
                left = left.next;
            }
            else{
                curr.next = right;
                right = right.next;
            }
            curr = curr.next;
        }
        curr.next = (left != null)? left: right;
        return dummy.next;
    }
    public ListNode sortList(ListNode head) {
        if(head == null ||  head.next == null){
            return head;
        }
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode secondHalf = slow.next;
        slow.next = null;
        
        ListNode left = sortList(head);
        ListNode right = sortList(secondHalf);
        
        return merge(left, right);
    }
}