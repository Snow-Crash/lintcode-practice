// 625-factorization.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/factorization
// ref: https://www.cnblogs.com/lz87/p/7494025.html
// ref: https://blog.csdn.net/qq_36754149/article/details/90515301

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here

        vector<int> factors;
        vector<vector<int>> result;

        dfs(n, 2, factors, result);

        return result;

    }

    void dfs(int n, int last_factor, vector<int>& factors, vector<vector<int>>& result)
    {

        if (n == 1)
        {
            if (factors.size() > 1)
                result.push_back(factors);
            return;
        }


        for (int i = last_factor; i <= sqrt(n); i++)
        {
            // i is a factor of n
            if (n % i == 0)
            {
                int new_n = n / i;

                factors.push_back(i);

                dfs(new_n, i, factors, result);

                factors.pop_back();
            }
        }

        factors.push_back(n);
        dfs(1, n, factors, result);
        factors.pop_back();

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
