class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def DFS(grid, i, j):
            if not (0 <= i < m) or not (0 <= j < n):
                return

            grid[i][j] = '0'
            if i > 0 and grid[i-1][j] == '1': #top
                DFS(grid, i-1, j)
            if i < m-1 and grid[i+1][j] == '1': #bottom
                DFS(grid, i+1, j)
            if j > 0 and grid[i][j-1] == '1': #left
                DFS(grid, i, j-1)
            if j < n-1 and grid[i][j+1] == '1': #right
                DFS(grid, i, j+1)

        m, n = len(grid), len(grid[0])
        count = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    DFS(grid, i, j)
                    count += 1

        return count