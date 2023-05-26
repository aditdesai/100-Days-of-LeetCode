class Solution {
public:
    
    int uniquePaths(int m, int n) {
        // robot can take m-1 downs and n-1 rights
        // arrange them
        // ans = (m+n-2)! / ((m-1)! . (n-1)!)

        // return (fact(m+n-2) / (fact(m-1) * fact(n-1)));
        // well, this caused integer overflows cz factorial was generating
        // numbers beyond the range of int and long
        // DP it is then, I guess :)

        // uniquePaths(m,n) = uniquePaths(m-1, n) + uniquePaths(m, n-1)

        /* TLE
        if (m == 1 || n == 1)
            return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
        */

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};