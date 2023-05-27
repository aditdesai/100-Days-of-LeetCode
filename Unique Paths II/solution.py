class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1:
            return 0

        grid = [[0 for _ in range(n)] for _ in range(m)]
        grid[0][0] = 1
        print(grid)

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue

                if obstacleGrid[i][j] == 1:
                    grid[i][j] = 0
                elif i == 0:
                    grid[0][j] = grid[0][j-1]
                elif j == 0:
                    grid[i][0] = grid[i-1][0]
                else:
                    grid[i][j] = grid[i-1][j] + grid[i][j-1]

        return grid[m-1][n-1]