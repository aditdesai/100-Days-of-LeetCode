class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []

        for i in range(len(nums)):
            heapq.heappush(heap, nums[i])
            if i >= k:
                heapq.heappop(heap)

        return heap[0]