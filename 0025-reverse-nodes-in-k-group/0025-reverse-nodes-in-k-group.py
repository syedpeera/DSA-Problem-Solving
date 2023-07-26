# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        if head is None or k==1:
            return head

        dummy=ListNode(0)
        dummy.next=head
        pre=cur=nex=dummy

        count=0
        while cur.next:
            count+=1
            cur=cur.next

        while count>=k:
            cur=pre.next
            nex=cur.next
            for i in range(1,k):
                cur.next=nex.next
                nex.next=pre.next
                pre.next=nex
                nex=cur.next
            count-=k
            pre=cur
        return dummy.next