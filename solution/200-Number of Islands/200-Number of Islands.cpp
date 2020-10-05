// 200-Number of Islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    vector<vector<char>> grid{ {'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'} };

    vector<vector<char>> grid2{ {'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'} };

    Solution solution;

    int res = solution.numIslands(grid2);
}
