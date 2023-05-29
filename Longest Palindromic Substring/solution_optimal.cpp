class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        string maxstr = s.substr(0, 1);
        for (int i = n-2; i >= 0; --i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if (s[i] == s[j] && (j-i == 1 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;

                    if (j-i+1 > maxstr.length())
                        maxstr = s.substr(i, j-i+1);
                }
            }
        }

        return maxstr;
    }
};