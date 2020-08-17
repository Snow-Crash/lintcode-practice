// 778-pacific-atlantic-water-flow.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/pacific-atlantic-water-flow/description
// ref: https://www.cnblogs.com/grandyang/p/5962508.html

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: The list of grid coordinates
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // write your code here

        int m = matrix.size();

        int n = 0;

        if (matrix.size() != 0)
            n = matrix[0].size();

        vector<vector<int>> pacific_mark(m, vector<int>(n, 0));
        vector<vector<int>> atlantic_mark(m, vector<int>(n, 0));


        for (int i = 0; i != m; i++)
        {
            dfs(matrix, pacific_mark, -1, i, 0);
            dfs(matrix, atlantic_mark, -1, i, n - 1);
        }

        for (int i = 0; i != n; i++)
        {
            dfs(matrix, pacific_mark, -1, 0, i);
            dfs(matrix, atlantic_mark, -1, m - 1, i);
        }

        vector<vector<int>> result;

        for (int i = 0; i != m; i++)
        {
            for (int j = 0; j != n; j++)
            {
                if (pacific_mark[i][j] == 1 && atlantic_mark[i][j] == 1)
                {
                    vector<int> coordinate = { i, j };
                    result.push_back(coordinate);
                }
            }
        }

        return result;

    }

    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& mark, int prev_val, int row, int col)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        if (matrix[row][col] < prev_val)
            return;

        if (mark[row][col] == 1)
            return;

        mark[row][col] = 1;

        dfs(matrix, mark, matrix[row][col], row, col - 1);

        dfs(matrix, mark, matrix[row][col], row, col + 1);

        dfs(matrix, mark, matrix[row][col], row - 1, col);

        dfs(matrix, mark, matrix[row][col], row + 1, col);

    }

};

int main()
{
    std::cout << "Hello World!\n";
}