// 1-59-two-sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/problems/two-sum
// https://www.lintcode.com/problem/two-sum/description

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> m;

        int i = 0;

        for (; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (m.count(nums[i]) == 0)
                m[temp] = i;
            else
                break;
        }

        return { m[nums[i]], i };
    }
};

int main()
{
    vector<int> n1{ 2,7,11,15 };
   
    Solution solution;
    
    vector<int> res = solution.twoSum(n1, 9);
}
