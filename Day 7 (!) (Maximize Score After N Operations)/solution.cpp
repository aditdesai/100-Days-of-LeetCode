class Solution {
public:

    int solve(vector<int> &nums, unordered_map<vector<bool>, int> &m, vector<bool> &visited, int i)
    {
        if(m.count(visited))
            return m[visited];
        int sum = 0, n = nums.size();
        for(int j = 0; j < n; ++j)
        {
            if (visited[j])
                continue;

            for(int k = j+1; k < n; ++k)
            {
                if (visited[k])
                    continue;

                visited[j] = true;
                visited[k] = true;

                sum = max(sum, i * __gcd(nums[j], nums[k]) + solve(nums, m, visited, i+1));

                visited[j] = false;
                visited[k] = false;
            }
        }
        m[visited] = sum;
        return sum;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_map<vector<bool>, int> m;

        return solve(nums, m, visited, 1);
    }
};