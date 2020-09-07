// 15-57-3sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/3sum
// https://www.lintcode.com/problem/3sum

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // set<int> s;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     s.insert(nums[i]);
        // }

        set<vector<int>> s;

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;

            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                continue;

            int a = 0 - nums[i];

            unordered_map<int, int> m;

            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                    continue;

                // if (j+1 < nums.size() && nums[j] == nums[j+1])
                //     continue;

                if (m.count(nums[j]) == 0)
                    m[a - nums[j]] = nums[j];
                else
                {
                    if (nums[i] < 0)
                        s.insert({ min(nums[i],  a - nums[j]), max( nums[i], a - nums[j]), nums[j] });
                    else
                        s.insert({ a - nums[j], nums[i], nums[j] });
                }

                //res.push_back({nums[i], a-nums[j], nums[j]});
            }
        }

        //for (auto it = s.begin(); it != s.end(); it++)
        //    res.push_back(vector<int>(it->begin(), it->end()));

        return vector<vector<int>>(s.begin(), s.end());
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> s;

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            else if (i == 0 || nums[i - 1] != nums[i])
                twosum(nums, i, res);

        }

        return res;
    };

    void twosum(vector<int> &nums, int idx, vector<vector<int>> &res)
    {

        int i = idx + 1;
        int j = nums.size() - 1;

        while (i < j)
        {
            int sum = nums[idx] + nums[i] + nums[j];

            if (sum < 0)
            {
                i++;
            }
            else if (sum > 0)
            {
                j--;
            }
            else
            {
                res.push_back({ nums[idx], nums[i], nums[j] });
                i++;
                j--;

                while (i < j && nums[i] == nums[i-1])
                {
                    i++;
                }
            }
        }
    }
};

class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> s;

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            else if (i == 0 || nums[i - 1] != nums[i])
                twosum(nums, i, res);

        }

        return res;
    };

    void twosum(vector<int>& nums, int idx, vector<vector<int>>& res)
    {
        //unordered_map<int, int> m;

        unordered_set<int> m;

        for (int i = idx + 1; i < nums.size(); i++)
        {
            int complement = -nums[idx] - nums[i];

            if (m.count(nums[i]) > 0)
            {
                res.push_back({nums[idx], complement, nums[i]});

                while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }
            else
            {
                m.insert(complement);
            }
        }
    }
};

int main()
{
    vector<int> v1{ 3,0,-2,-1,1,2 };

    vector<int> v2{ -1,0,1,2,-1,-4 };

    vector<int> v3{ 0,0,0 };


    Solution3 solution;

    solution.threeSum(v3);
}
