// 153-combination-sum-ii.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/combination-sum-ii/description
// ref: http://www.cnblogs.com/grandyang/p/4419386.html

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        // write your code here

        sort(num.begin(), num.end());

        vector<vector<int>> result;
        vector<int> comb;

        vector<int> used(num.size(), 0);

        dfs(result, comb, num, used, 0, target, 0);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& comb, vector<int>& num, vector<int>& used, int sum, int target, int start)
    {
        if (sum == target)
        {
            result.push_back(comb);
            return;
        }

        for (int i = start; i != num.size(); i++)
        {
            if (used[i] == 1)
                continue;

            if (i >= 1 && used[i-1] == 0 && num[i - 1] == num[i])
                continue;

            int temp_sum = sum + num[i];

            if (temp_sum <= target)
            {
                comb.push_back(num[i]);
                used[i] = 1;
                dfs(result, comb, num, used, temp_sum, target, i + 1);
                used[i] = 0;
                comb.pop_back();
            }
            else
                break;
        }
    }
};

int main()
{
    Solution solution;

    vector<int> num = { 7,1,2,5,1,6,10 };

    vector<vector<int>> result = solution.combinationSum2(num, 8);
}

