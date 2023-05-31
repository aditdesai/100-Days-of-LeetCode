class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        for character in ransomNote:
            if character not in magazine:
                return False
            else:
                i = magazine.index(character)
                magazine = magazine[:i] + magazine[i+1:]
        
        return True