class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]

        for i in range(n):
            dp[i][i] = True
        
        maxstr = s[0]

        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                dp[i][j] = s[i] == s[j] and (j-i == 1 or dp[i+1][j-1])

                if dp[i][j] and len(maxstr) < j-i+1:
                    maxstr = s[i:j+1]

        return maxstr