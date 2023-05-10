#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;

        visited[i][j] = 1;
        if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) //top
            DFS(grid, visited, i-1, j);
        
        if(i < grid.size()-1 && grid[i+1][j] == '1' && !visited[i+1][j]) //bottom
            DFS(grid, visited, i+1, j);

        if(j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]) // left
            DFS(grid, visited, i, j-1);

        if(j < grid[0].size()-1 && grid[i][j+1] == '1' && !visited[i][j+1]) //right
            DFS(grid, visited, i, j+1);

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        int count = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    DFS(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };

    Solution s;
    cout << s.numIslands(grid) << endl;

    return 0;
}