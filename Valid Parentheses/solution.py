class Solution:
    def isValid(self, s: str) -> bool:
        n = len(s)
        if n == 0:
            return True
        if n == 1:
            return False

        stack = []

        for i in range(n):
            ch = s[i]
            if ch in ['(', '{', '[']:
                stack.append(ch)
            elif len(stack) == 0:
                return False
            else:
                ch2 = stack.pop()
                if (ch2, ch) not in [('(', ')'), ('{', '}'), ('[', ']')]:
                    return False
        
        return not stack