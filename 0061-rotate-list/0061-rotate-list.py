from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head  # Return original list instead of None
        
        # Step 1: Find the length of the linked list
        length = 1
        last = head
        while last.next:
            last = last.next
            length += 1
        
        # Step 2: Create a circular linked list
        last.next = head  # Connect last node to the head
        
        # Step 3: Find the new tail (length - k % length - 1)
        k = k % length
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next
        
        # Step 4: Break the circular link and update head
        new_head = new_tail.next
        new_tail.next = None  # Break the loop
        
        return new_head
