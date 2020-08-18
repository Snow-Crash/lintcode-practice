// 11-383-container-with-most-water.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://leetcode.com/problems/container-with-most-water
// https://www.lintcode.com/problem/container-with-most-water/description

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;

        int res = 0;

        while (i < j)
        {
            res = max(res, min(height[i], height[j]) * (j - i));

            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};
int main()
{
    vector<int> v1{ 1,8,6,2,5,4,8,3,7 };

    Solution solution;

    int res = solution.maxArea(v1);
}
