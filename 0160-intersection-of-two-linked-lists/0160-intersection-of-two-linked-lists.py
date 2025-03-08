# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
            if not headA or not headB:
                return None

            slow=headA
            fast=headB

            while slow != fast:
                slow = headB if slow is None else slow.next
                fast = headA if fast is None else fast.next

            return slow