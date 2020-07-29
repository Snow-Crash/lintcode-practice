// 433-number-of-islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // write your code here


        int m = grid.size();
        int n = 0;
        if (m > 0)
            n = grid[0].size();

        int result = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int row = 0; row != m; row++)
        {
            for (int col = 0; col != n; col++)
            {
                if (grid[row][col] == 0 || visited[row][col] == 1)
                    continue;

                dfs(grid, visited, row, col);
                result++;
            }
        }

        return result;
    }


    void dfs(vector<vector<bool>>& grid, vector<vector<int>>& visited, int row, int col)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        if (visited[row][col] == 1 || grid[row][col] == 0)
            return;

        visited[row][col] = 1;

        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row, col + 1);
        dfs(grid, visited, row, col - 1);

    }
};

int main()
{
    Solution solution;

    vector <vector<bool>> grid{ {1, 1, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 1} };

    int result = solution.numIslands(grid);
}