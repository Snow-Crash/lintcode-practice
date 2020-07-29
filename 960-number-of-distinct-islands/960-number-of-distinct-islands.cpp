// 960-number-of-distinct-islands.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/number-of-distinct-islands/description
// ref: https://www.cnblogs.com/grandyang/p/7698778.html

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    int numberofDistinctIslands(vector<vector<int>>& grid) {
        // write your code here

        int m = grid.size();
        int n = 0;

        if (m != 0)
            n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        set<vector<vector<int>>> result;

        for (int row = 0; row != m; row++)
        {
            for (int col = 0; col != n; col++)
            {
                if (grid[row][col] != 1)
                    continue;

                vector<vector<int>> path;

                dfs(grid, visited, row, col, row, col, path);

                if (path.size() != 0)
                    result.insert(path);
            }
        }

        return result.size();

    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int start_row, int start_col, int row, int col, vector<vector<int>>& path)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (row >= m || col >= n || row < 0 || col < 0 || grid[row][col] == 0 || visited[row][col] == 1)
            return;

        visited[row][col] = 1;

        int row_offset = row - start_row;
        int col_offset = col - start_col;

        vector<int> coordinate{ row_offset,col_offset };

        path.push_back(coordinate);

        dfs(grid, visited, start_row, start_col, row + 1, col, path);
        dfs(grid, visited, start_row, start_col, row - 1, col, path);
        dfs(grid, visited, start_row, start_col, row, col + 1, path);
        dfs(grid, visited, start_row, start_col, row, col - 1, path);

    }
};

int main()
{

}