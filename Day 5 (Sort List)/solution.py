# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, left, right):
        if not left:
            return right
        if not right:
            return left

        dummy = ListNode(0)
        curr = dummy
        
        while left and right:
            if left.val <= right.val:
                curr.next = left
                left = left.next
            else:
                curr.next = right
                right = right.next

            curr = curr.next
        
        curr.next = left or right # in merge sort, only one element will be left

        return dummy.next


    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]: # merge sort
        if not head or not head.next:
            return head

        slow = fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        mid = slow.next
        slow.next = None

        left = self.sortList(head)
        right = self.sortList(mid)

        return self.merge(left, right)