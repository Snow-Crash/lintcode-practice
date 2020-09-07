// 48-rotate-image.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n / 2 + n % 2; i++)
        {
            for (int j = i; j < n - i-1; j++)
            {

                //save left
                int temp = matrix[j][i];

                //bottom to left
                matrix[j][i] = matrix[n - i - 1][j];

                // right to bottom
                matrix[n-i-1][j] = matrix[n-j-1][n-i-1];

                //top to right
                matrix[n-j-1][n-i-1] = matrix[i][n-j-1];

                //left to top
                matrix[i][n - j - 1] = temp;
            }
        }
    }
};

int main()
{
    vector<vector<int>> mat1{ {1,2,3},{4,5,6},{7,8,9} };
    
    Solution solution;

    solution.rotate(mat1);
};
