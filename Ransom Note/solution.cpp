class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ch;

        for (int i = 0; i < magazine.length(); ++i)
            ch[magazine[i]] += 1;

        for (int i = 0; i < ransomNote.length(); ++i)
        {
            /*
            if (ch[ransomNote[i]])
                ch[ransomNote[i]]--;
            */
            if (ch.find(ransomNote[i]) != ch.end() && ch[ransomNote[i]] > 0)
                ch[ransomNote[i]] -= 1;
            else
                return false;
        }

        return true;
    }
};