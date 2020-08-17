// 152-Combinations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/combinations/description
// ref: https://www.cnblogs.com/grandyang/p/4332522.html

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here

        vector<vector<int> > result;
        vector<int> comb;

        dfs2(result, comb, 1, n, k);

        return result;

    }

    void dfs(vector<vector<int> >& result, vector<int> comb, int level, int n, int k)
    {
        if (comb.size() == k)
        {
            result.push_back(comb);
            return;
        }

        for (int i = level; i <= n; i++)
        {
            comb.push_back(i);
            dfs(result, comb, i + 1, n, k);
        }
    }

    void dfs2(vector<vector<int> >& result, vector<int> comb, int level, int n, int k)
    {
        if (comb.size() == k)
        {
            result.push_back(comb);
            return;
        }

        for (int i = level; i <= n; i++)
        {
            vector<int> temp_comb = comb;
            temp_comb.push_back(i);
            dfs2(result, temp_comb, i + 1, n, k);
        }
    }
};
int main()
{
    std::cout << "Hello World!\n";

    Solution solution;


    vector<vector<int> > result = solution.combine(4, 2);

}