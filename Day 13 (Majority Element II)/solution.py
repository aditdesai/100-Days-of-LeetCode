class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        maj1 = maj2 = None
        count1 = count2 = 0

        for num in nums:
            if maj1 == num:
                count1 += 1
            elif maj2 == num:
                count2 += 1
            elif count1 == 0:
                maj1 = num
                count1 = 1
            elif count2 == 0:
                maj2 = num
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        count1 = nums.count(maj1)
        count2 = nums.count(maj2)

        res = []

        if count1 > len(nums) // 3:
            res.append(maj1)
        if count2 > len(nums) // 3:
            res.append(maj2)

        return res