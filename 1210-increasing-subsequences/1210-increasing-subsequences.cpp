// 1210-increasing-subsequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: all the different possible increasing subsequences of the given array
     */
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // Write your code here

        set<vector<int>> result;

        vector<int> seq;

        for (int i = 0; i != nums.size(); i++)
        {
            seq.push_back(nums[i]);
            dfs(nums, result, i, seq);
            seq.pop_back();
        }

        vector<vector<int>> res;
        for (auto it = result.begin(); it != result.end(); it++)
        {
            res.push_back(*it);
        }

        return res;
    }

    void dfs(vector<int>& nums, set<vector<int>>& result, int start, vector<int>& seq)
    {
        if (start >= nums.size())
        {
            if (seq.size() >= 2)
                result.insert(seq);

            return;
        }

        if (seq.size() >= 2)
            result.insert(seq);

        for (int i = start + 1; i != nums.size(); i++)
        {
            if (nums[i] >= seq.back())
            {
                seq.push_back(nums[i]);
                dfs(nums, result, i, seq);
                seq.pop_back();
            }
        }
    }
};

int main()
{
    Solution solution;

    vector<int> array {4, 6, 7, 7};

    solution.findSubsequences(array);
}
