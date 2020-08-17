// 57-3sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/3sum/description

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int>& numbers) {
        // write your code here

        quicksort(numbers, 0, numbers.size() - 1);

        set<vector<int>> res;

        vector<int> triplet;

        for (int i = 0; i != numbers.size(); i++)
        {
            triplet.push_back(numbers[i]);
            dfs(numbers, res, triplet, i + 1, 0, numbers[i]);
            triplet.pop_back();
        }

        vector<vector<int>> result;

        for (auto it = res.begin(); it != res.end(); it++)
        {
            result.push_back(*it);
        }

        return result;
    }

    void quicksort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = nums[left];

        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (nums[i] > pivot && nums[j] < pivot)
                swap(nums[i], nums[j]);

            if (nums[i] <= pivot)
                i++;

            if (nums[j] >= pivot)
                j--;
        }

        swap(nums[left], nums[j]);

        quicksort(nums, left, j - 1);
        quicksort(nums, j + 1, right);
    }

    void dfs(vector<int>& nums, set<vector<int>>& res, vector<int>& triplet, int idx, int depth, int sum)
    {
        if (triplet.size() == 3)
        {
            if (sum == 0)
                res.insert(triplet);

            return;
        }

        if (idx + 3 - triplet.size() > nums.size())
            return;

        if (nums[idx] > 0 && sum >= 0)
            return;

        for (int i = idx; i != nums.size(); i++)
        {
            int new_sum = sum + nums[i];
            triplet.push_back(nums[i]);
            dfs(nums, res, triplet, i + 1, depth + 1, new_sum);

            triplet.pop_back();
        }

    }
};

int main()
{
    Solution solution;

    vector<int> numbers{ 1,0,-1,-1,-1,-1,0,1,1,1 };

    vector<vector<int>> result = solution.threeSum(numbers);

}
