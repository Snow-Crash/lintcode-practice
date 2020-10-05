# 200. Number of Islands

<https://leetcode.com/problems/number-of-islands/>

## Summary

Use DFS. Use 2d array visited to record if a point in the grid is visited. for every point in the grid, if the point is 1 and not visited, start dfs. The number of islands is the number of dfs executed.

## Solution

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.size() == 0)
            return 0;

        if (grid[0].size() == 0)
            return 0;

        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));

        int cnt = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == '1')
                {
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;

    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
        int row, int col)
    {
        if (row < 0 || row >= grid.size())
            return;

        if (col < 0 || col >= grid[0].size())
            return;

        if (visited[row][col] == 1)
            return;

        if (grid[row][col] == '0')
            return;

        visited[row][col] = 1;

        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row, col + 1);
        dfs(grid, visited, row, col - 1);

        return;
    }
};
```
