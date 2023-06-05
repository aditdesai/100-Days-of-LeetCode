class Solution:
    def reverse(self, x: int) -> int:
        if x > -10 and x < 10:
            return x
            
        rev = 0
        limit = 2 ** 31
        sign  = x // abs(x)
        x *= sign
        while x != 0:
            if rev > limit/10:
                return 0
            rev = (rev * 10) + (x % 10)
            x //= 10

        return sign * rev