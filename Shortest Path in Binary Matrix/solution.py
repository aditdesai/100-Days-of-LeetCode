class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] or grid[-1][-1]:
            return -1
        n = len(grid)
        if n == 1:
            return 1

        q = [(0, 0, 1)] # row, col, length
        visited = set((0, 0))
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]

        while q:
            # get front of queue
            row, col, length = q.pop(0)

            

            # add neighbours to queue
            for dx, dy in directions:
                newx = row + dx
                newy = col + dy

                if min(newx, newy) >= 0 and max(newx, newy) < n and grid[newx][newy] == 0 and (newx, newy) not in visited:
                    if newx == n-1 and newy == n-1:
                        return length+1

                    q.append((newx, newy, length+1))
                    visited.add((newx, newy)) # mark as visited
            

        return -1