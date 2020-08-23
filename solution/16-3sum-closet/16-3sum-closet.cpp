// 16-3sum-closet.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/3sum-closest

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int diff = INT_MAX;

        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
                twosum(nums, target, i, diff, res);
        }
        return res;
    }

    void twosum(vector<int>& nums, int target, int idx, int& diff, int& res)
    {
        int i = idx + 1;
        int j = nums.size()-1;

        while (i < j)
        {
            int sum = nums[i] + nums[j] + nums[idx];

            int d = abs(target - sum);

            if (d < diff)
            {
                diff = d;
                res = sum;
            }

            if (sum < target)
                i++;
            else if (sum > target)
                j--;
            else
            {
                i++;
                j--;
            }
        }
    }
};

int main()
{
    vector<int> v1{ -1,2,1,-4 };
    vector<int> v2{ 1,1,1,1 };

    Solution solution;

    int res1 = solution.threeSumClosest(v1, 1);

    int res2 = solution.threeSumClosest(v2, 0);

}
