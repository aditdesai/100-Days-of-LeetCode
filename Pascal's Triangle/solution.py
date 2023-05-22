class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [[1] * x for x in range(1, numRows+1)]

        if numRows <= 2:
            return res

        for i in range(2, numRows):
            for j in range(1, i):
                res[i][j] = res[i-1][j-1] + res[i-1][j]

        return res