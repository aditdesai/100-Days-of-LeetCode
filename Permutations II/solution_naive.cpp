class Solution {
private:
    void permute(vector<int> &nums, set<vector<int>> &permutations, int l)
    {
        if (l == nums.size()-1)
        {
            permutations.insert(nums);
            return;
        }

        for(int i = l; i < nums.size(); ++i)
        {
            swap(nums[i], nums[l]);
            permute(nums, permutations, l+1);
            swap(nums[i], nums[l]); // backtrack
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> permutations;
        permute(nums, permutations, 0);

        vector<vector<int>> result;
        for (auto &p : permutations)
        {
            result.push_back(p);
        }

        return result;
    }
};