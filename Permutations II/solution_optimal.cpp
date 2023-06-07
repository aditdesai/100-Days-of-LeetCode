class Solution {

public:
        void permute(vector<vector<int>>& result, vector<int> nums, int pos) 
        {
        if (pos == nums.size()) 
            result.push_back(nums);
        else 
        {
            for (int i = pos; i < nums.size(); ++i) 
            {
                if (i != pos && nums[i] == nums[pos]) 
                    continue;
                swap(nums[pos], nums[i]);
                permute(result, nums, pos + 1);
                // nums passed by value so no swap back
            }
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // to make sure identical elements are adjacent to each other
        vector<vector<int>> result;
        permute(result, nums, 0);
        return result;
    }
};