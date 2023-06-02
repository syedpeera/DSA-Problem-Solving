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
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b)-> a.val - b.val);
        for(ListNode element: lists){
            if(element!=null){
                minHeap.add(element);
            }
        }
        ListNode head=null;
        ListNode tail=null;
        while(!minHeap.isEmpty()){
            ListNode curr = minHeap.poll();
            if(head==null){
                head = curr;
                tail = curr;
            }
            else{
                tail.next = curr;
                tail = curr;
            }
            if(curr.next!=null){
                minHeap.add(curr.next);
            }
        }
        return head;
    }
}