# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return

        slow=fast=head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        
        prev=None
        current=slow
        while current:
            next_temp=current.next
            current.next=prev
            prev=current
            current=next_temp

        first=head
        second=prev

        while second.next:
            temp1=first.next
            temp2=second.next
            first.next=second
            second.next=temp1
            first = temp1
            second = temp2