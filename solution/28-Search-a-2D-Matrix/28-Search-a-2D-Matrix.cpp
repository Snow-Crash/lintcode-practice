// 28-Search-a-2D-Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // write your code here

        int m = matrix.size();
        int n = matrix[0].size();


        int start = 0;
        int end = m - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;


            if (matrix[mid].back() >= target)
            {
                start = start;
                end = mid;
            }
            else
            {
                start = mid + 1;
                end = end;
            }
        }

        int row = start;

        int col_start = 0;
        int col_end = n - 1;

        while (col_start < col_end)
        {
            int mid = (col_start + col_end) / 2;

            if (matrix[row][mid] >= target)
            {
                col_start = col_start;
                col_end = mid;
            }
            else
            {
                col_start = mid + 1;
                col_end = col_end;
            }
        }

        int col = col_start;

        return matrix[row][col] == target;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> v1{ {1,2,4}, {6,7,8} };

    vector<vector<int>> v2{ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };

    vector<vector<int>> v3{ {1,4,5}, {6,7,8} };

    bool result = solution.searchMatrix(v3, 6);
}