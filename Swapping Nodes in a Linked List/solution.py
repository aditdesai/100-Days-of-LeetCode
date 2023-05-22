# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        curr = slow = head

        for _ in range(k-1):
            curr = curr.next

        fast = curr

        while fast.next:
            slow = slow.next
            fast = fast.next

        slow.val, curr.val = curr.val, slow.val

        return head