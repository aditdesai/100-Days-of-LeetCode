class Solution:
    
    def permuteHelper(self, nums, l, r, result):
        if l > r:
            #print(nums)
            result.append(nums[:])
        else:
            for i in range(l, r+1):
                nums[l], nums[i] = nums[i], nums[l]
                self.permuteHelper(nums, l+1, r, result)
                nums[l], nums[i] = nums[i], nums[l] #backtrack
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.permuteHelper(nums, 0, len(nums)-1, result)
        return result