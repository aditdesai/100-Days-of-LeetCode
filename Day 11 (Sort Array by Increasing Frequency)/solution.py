class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        freq = {}
        for num in nums:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1

        new_nums = []

        while freq:
            m = min(freq, key=lambda x:freq[x])
            new_nums.extend([m] * freq[m])
            del freq[m]

        return new_nums