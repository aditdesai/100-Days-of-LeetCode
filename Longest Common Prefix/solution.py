class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        strs.sort()

        i = 0
        s1, s2, prefix = strs[0], strs[-1], ""
        while i < min(len(s1), len(s2)) and s1[i] == s2[i]:
            prefix += s1[i]
            i += 1

        return prefix