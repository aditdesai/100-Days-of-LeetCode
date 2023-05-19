class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can max only be 2 elements that occur more than floor(n/3) times

        unordered_map<int, int> freq;
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
            freq[nums[i]]++;
        

        for (auto i = freq.begin(); i != freq.end(); ++i)
        {
            if (i->second > n/3)
                res.push_back(i->first);
        }

        return res;
        


    }
};