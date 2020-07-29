// 434-number-of-islands-ii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // write your code here

        vector<vector<int>> grid(n, vector<int>(m, 0));

        int count = 0;
        vector<int> result;


        for (int i = 0; i != operators.size(); i++)
        {
            int x = operators[i].x;
            int y = operators[i].y;

            grid[x][y] = 1;

            bool up = check(grid, x + 1, y, n, m);
            bool down = check(grid, x - 1, y, n, m);
            bool left = check(grid, x, y + 1, n, m);
            bool right = check(grid, x, y - 1, n, m);

            if (up == false && down == false && right == false && left == false)
                count++;

            result.push_back(count);
        }

        return result;
    }

    bool check(vector<vector<int>>& grid, int row, int col, int n, int m)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;

        if (grid[row][col] == 1)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<vector<int>> coordinates { {1, 1}, {1, 2}, {1, 3}, {1, 4}};

    vector<Point> operators;

    for (int i = 0; i != coordinates.size(); i++)
    {
        Point p(coordinates[i][0], coordinates[i][1]);
        operators.push_back(p);
    }

    Solution solution;

    vector<int> result = solution.numIslands2(4, 5, operators);
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
