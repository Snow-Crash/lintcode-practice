// 33-n-queens.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/n-queens/note
// ref: https://www.cnblogs.com/grandyang/p/4377782.html

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        // write your code here

        vector<string> grid(n, string(n, '.'));

        vector<vector<string>> solution;

        dfs(solution, grid, 0);

        return solution;

    }


    void dfs(vector<vector<string>>& solution, vector<string>& grid, int row)
    {
        if (row == grid.size())
        {
            solution.push_back(grid);
            return;
        }

        for (int col = 0; col != grid.size(); col++)
        {
            bool valid = validate(grid, row, col);

            if (valid == true)
            {
                grid[row][col] = 'Q';
                dfs(solution, grid, row + 1);
                grid[row][col] = '.';
            }
        }
    }

    bool validate(vector<string>& grid, int row, int col)
    {
        // check if Q exist in same col
        for (int i = 0; i < row; i++)
        {
            if (grid[i][col] == 'Q')
                return false;
        }

        // check if in diagonal line
        //i for row, j for column
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 'Q')
                return false;
        }

        //another diagonal line
        for (int i = row - 1, j = col + 1; i >= 0 && j < grid.size(); i--, j++)
        {
            if (grid[i][j] == 'Q')
                return false;
        }

        return true;
    }

};

int main()
{
    Solution solution;

    vector<vector<string>> result = solution.solveNQueens(3);


    std::cout << "Hello World!\n";
}