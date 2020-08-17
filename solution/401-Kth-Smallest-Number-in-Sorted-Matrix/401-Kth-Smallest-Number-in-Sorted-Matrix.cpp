// 401-Kth-Smallest-Number-in-Sorted-Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // write your code here

        int rank = 1;

        priority_queue <int, vector<int>, greater<int>> q;

        for (int i = 0; i != matrix.size(); i++)
        {
            for (int j = 0; j != matrix[0].size(); j++)
            {
                q.push(matrix[i][j]);
            }
        }

        while (q.empty() == false && rank <= k)
        {
            if (rank == k)
                return q.top();
            else
            {
                rank++;
                q.pop();
            }
        }

    }
};

int main()
{
    std::cout << "Hello World!\n";

    vector<vector<int>> m1{ {1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7}, {4,5,6,7,8}};

    vector<vector<int>> m2{ {1}, {2}, {3}, {100}, {101}, {1000}, {9999} };

    Solution solution;

    int result = solution.kthSmallest(m2, 5);


}
