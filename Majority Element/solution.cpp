class Solution {
public:
    int majorityElement(vector<int>& nums) { //voting algorithm
        int maj, count = 0, n = nums.size();
        
        if (n == 1)
            return nums[0];
        
        for(int i = 0; i < n; ++i)
        {
            if (count == 0)
            {
                maj = nums[i];
                count = 1;
            }
            else if (nums[i] == maj)
                ++count;
            else
                --count;
        }

        return maj;
    }
};