class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        int i = 0;
        string s1 = strs[0], s2 = strs[n-1], prefix = "";
        while (i < s1.length() && i < s2.length())
        {
            if (s1[i] != s2[i])
                break;

            prefix += s1[i];
            i++;
        }

        return prefix;
    }
};