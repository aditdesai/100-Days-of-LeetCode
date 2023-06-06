class Solution {
private:
    void perm(vector<int> &nums, vector<vector<int>> &permutations, int l)
    {
        if (l == nums.size()-1)
        {
            permutations.push_back(nums);
            return;
        }
        for(int i = l; i < nums.size(); ++i)
        {
            swap(nums[l], nums[i]);
            perm(nums, permutations, l+1);
            swap(nums[l], nums[i]); // backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        perm(nums, permutations, 0);

        return permutations;
    }
};