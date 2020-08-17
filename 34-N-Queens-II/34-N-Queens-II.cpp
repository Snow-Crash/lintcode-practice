// 34-N-Queens-II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here

        int cnt = 0;

        vector<vector<int>> grid(n, vector<int>(n, 0));

        dfs(grid, 0, cnt);

        return cnt;
    }

    void dfs(vector<vector<int>>& grid, int x, int& cnt)
    {
        if (x == grid.size())
        {
            cnt++;
            return;
        }

        for (int i = 0; i != grid.size(); i++)
        {
            bool valid = check(grid, x, i);
            if (valid)
            {
                grid[x][i] = 1;
                dfs(grid, x + 1, cnt);
                grid[x][i] = 0;
            }
        }
    }

    bool check(vector<vector<int>>& grid, int x, int y)
    {
        int n = grid.size();

        for (int i = 0; i != n; i++)
        {
            if (grid[i][y] == 1)
                return false;
        }

        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 1)
                return false;
        }

        for (int i = x - 1, j = y + 1; i >= 0 && j < grid.size(); i--, j++)
        {
            if (grid[i][j] == 1)
                return false;
        }

        return true;
    }

};

int main()
{
    Solution solution;

    int res = solution.totalNQueens(3);

}
