class Solution:
    def maxScore(self, nums: List[int]) -> int:
        cache = {} #memoisation

        def dfs(nums, i):
            sum = 0
            n = len(nums)
            for j in range(n):
                for k in range(j+1, n):
                    new_nums = nums[:j] + nums[j+1:k] + nums[k+1:]
                    if (new_nums, i+1) not in cache:
                        cache[(new_nums, i+1)] = dfs(new_nums, i+1)
                        
                    sum = max(sum, i * gcd(nums[j], nums[k]) + cache[(new_nums, i+1)])

            return sum

        return dfs(tuple(nums), 1)