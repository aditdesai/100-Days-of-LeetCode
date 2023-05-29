class Solution {
public:
    bool isPalindrome(string s)
    {
        int n = s.length();
        for(int i = 0; i < n/2; ++i)
        {
            if (s[i] != s[n-1-i])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0 || n == 1)
            return s;

        for (int i = n; i > 0; --i)
        {
            for(int j = 0; j+i <= n; ++j)
            {
                string sub = s.substr(j, i);
                cout << sub << "\n";
                if (isPalindrome(sub))
                    return sub;
            }
        }

        return "";
    }
};