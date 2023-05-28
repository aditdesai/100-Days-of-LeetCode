class Solution {
public:
    int kthFactor(int n, int k) {
        if (n == 1)
        {
            if (k == 1)
                return 1;
            return -1;
        }

        vector<int> factors = {1, n};
        int left = 0, right = 1;

        for(int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                ++left;
                ++right;
                factors.insert(factors.begin()+left, i);
                
                if (i != n/i)
                    factors.insert(factors.begin()+right, n/i);
                
            }
        }

        if (factors.size() < k)
            return -1;
        return factors[k-1];
    }
};