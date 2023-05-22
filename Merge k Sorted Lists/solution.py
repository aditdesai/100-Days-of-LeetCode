# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        minHeap = []

        for node in lists:
            while node:
                minHeap.append(node)
                node = node.next

        minHeap.sort(key=lambda x:x.val)

        dummy = ListNode(0)
        curr = dummy

        for node in minHeap:
            curr.next = node
            curr = curr.next

        return dummy.next