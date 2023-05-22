class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can max only be 2 elements that occur more than floor(n/3) times
        // find 2 most occuring numbers and then check for > floor(n/3)

        int maj1, maj2, count1 = 0, count2 = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            if (maj1 == nums[i])
                count1++;
            else if (maj2 == nums[i])
                count2++;
            else if (count1 == 0)
            {
                maj1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                maj2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;

        for(int i = 0; i < n; ++i)
        {
            if (maj1 == nums[i])
                count1++;
            if (maj2 == nums[i])
                count2++;
        }

        vector<int> res;
        if (count1 > n/3)
            res.push_back(maj1);
        if (count2 > n/3)
            res.push_back(maj2);

        return res;
        
    }
};