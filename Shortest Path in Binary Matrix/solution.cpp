class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>> grid) { // BFS
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1])
            return -1;
        if (n == 1)
            return 1;

        queue<pair<int, int>> q;
        q.push({0, 0}); //row, col
        grid[0][0] = 1;

        // to mark visited cell, set grid[i][j] = length of path
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

        while (!q.empty())
        {
            // take element at front
            auto [row, col] = q.front();
            q.pop();

            // add neighbours
            for (int i = 0; i < 8; ++i)
            {
                int newx = row+dir[i].first;
                int newy = col+dir[i].second;

                if (newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] == 0)
                {
                    if (newx == n-1 && newy == n-1)
                        return grid[row][col] + 1;
                    q.push({newx, newy});

                    grid[newx][newy] = grid[row][col] + 1;
                }
            }
            
        }

        return -1;
    }
};