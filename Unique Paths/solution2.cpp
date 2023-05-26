class Solution {
public:
    int uniquePaths(int m, int n) {
        // ans = (m+n-2)! / ((m-1)! . (n-1)!)
        // cancelling one of the terms in denominator
        long res = 1;
        for(int i = m+n-2, j = 1; j < min(m,n); --i, ++j)
            res = (res * i) / j;
        return res;
    }
};