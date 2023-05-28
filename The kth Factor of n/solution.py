class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        if n == 1:
            if k == 1:
                return 1
            else:
                return -1

        factors = [1, n]
        left, right = 0, -1
        
        for i in range(2, int(sqrt(n)+1)):
            if n % i == 0:
                factors.insert(left+1, i)
                left += 1
                if i != n//i:
                    factors.insert(right, n//i)
                    right -= 1
            
        if k > len(factors):
            return -1
        return factors[k-1]