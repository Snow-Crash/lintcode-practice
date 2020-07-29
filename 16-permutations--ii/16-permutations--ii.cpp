// 16-permutations--ii.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/permutations-ii/description
// ref: https://www.cnblogs.com/grandyang/p/4359825.html

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // write your code here

        vector<vector<int>> result;

        //sort nums
        sort(nums.begin(), nums.end());

        vector<int> permute;
        vector<int> visited(nums.size(), 0);

        dfs(0, nums, permute, visited, result);

        return result;

    }

    void dfs(int level, vector<int>& nums, vector<int>& permute, vector<int> visited, vector<vector<int>>& result)
    {
        if (level >= nums.size())
        {
            result.push_back(permute);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i] == 1)
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
                continue;

            vector<int> temp_visited = visited;
            temp_visited[i] = 1;
            vector<int> temp_permute = permute;
            temp_permute.push_back(nums[i]);

            dfs(level + 1, nums, temp_permute, temp_visited, result);
        }
    }
};

int main()
{
    Solution solution;

    vector<int> nums = { 1, 2, 2 };

    vector<vector<int> > result = solution.permuteUnique(nums);

    std::cout << "Hello World!\n";
}
