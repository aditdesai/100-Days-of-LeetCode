class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n == 0)
            return true;
        if (n == 1)
            return false;

        stack<int> st;

        for (int i = 0; i < n; ++i)
        {
            char ch1 = s[i];
            if (ch1 == '(' || ch1 == '{' || ch1 == '[')
                st.push(ch1);
            else if (st.empty())
                return false;
            else
            {
                char ch2 = st.top();
                if ((ch2 == '(' && ch1 != ')') || (ch2 == '{' && ch1 != '}') || (ch2 == '[' && ch1 != ']'))
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};