class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        // find largest non increasing suffix
        for (i = n-1; i > 0; --i)
        {
            if (nums[i-1] < nums[i])
                break;
        }

        // handles descending order case
        if (i == 0)
        {
            for (int j = 0; j < n/2; ++j)
            {
                int t = nums[j];
                nums[j] = nums[n-1-j];
                nums[n-1-j] = t;
            }
            return;
        }

        // find number just greater than nums[i-1] and swap them
        for (int j = n-1; j >= i; --j)
        {
            if (nums[j] > nums[i-1])
            {
                int t = nums[j];
                nums[j] = nums[i-1];
                nums[i-1] = t;

                break;
            }
        }

        // reverse nums[i to n-1] => descending to ascending
        for (int j = 0; j < (n-i)/2; ++j)
        {
            int t = nums[j+i];
            nums[j+i] = nums[n-1-j];
            nums[n-1-j] = t;
        }
    }
};