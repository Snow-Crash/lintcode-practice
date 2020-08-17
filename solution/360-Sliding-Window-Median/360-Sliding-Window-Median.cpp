// 360-Sliding-Window-Median.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://blog.csdn.net/qq_43152052/article/details/102612895
// https://www.cnblogs.com/grandyang/p/6620334.html

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int>& nums, int k) {
        // write your code here

        vector<int> result;

        int l = 0;
        int r = 0;

        for (; r < nums.size(); r++)
        {

            if (r - l + 1 == k)
            {
                vector<int> v(nums.begin() + l, nums.begin() + l + k);
                sort(v.begin(), v.end());

                result.push_back(v[(v.size() -1)/ 2]);

                l++;
            }

        }

        return result;

    }
};

class Solution2 {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int>& nums, int k) {
        // write your code here

        vector<int> result;

        multiset<int> s(nums.begin(), nums.begin() + k);

        auto mid = next(s.begin(), (k - 1) / 2);


        for (int i = k; i <= nums.size(); i++)
        {
            result.push_back(*mid);

            if (i == nums.size())
                break;

            s.insert(nums[i]);

            if (nums[i] < *mid)
                mid--;

            if (nums[i - k] <= *mid)
                mid++;

            s.erase(s.lower_bound(nums[i - k]));
        }

        return result;


    }
};

int main()
{
    vector<int> v1{ 10 };

    vector<int> v2{ 1,2,7,8,5 };

    vector<int> v3{ 1,2,7,7,2,10,3,4,5 };

    vector<int> v4{};


    Solution2 solution;

    vector<int> result = solution.medianSlidingWindow(v4, 0);
}
