// 362-Sliding-Window-Maximum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/sliding-window-maximum/description
// https://blog.csdn.net/qq_43152052/article/details/102528600

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // write your code here

        vector<int> result;

        std::deque<int> q;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < k && i < nums.size())
            {
                while (q.empty() == false && nums[i] > nums[q.back()])
                {
                    q.pop_back();
                }

                q.push_back(i);

                if (i == k - 1)
                    result.push_back(nums[q.front()]);

            }
            else
            {
                if (q.empty() == false && q.front() <= i - k)
                    q.pop_front();

                while (q.empty() == false && nums[i] > nums[q.back()])
                    q.pop_back();


                q.push_back(i);

                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};

int main()
{

    vector<int> v1{ 142,38,100,53,22,84,168,50,194,136,111,13,47,45,151,164,126,47,106,124,183,8,87,38,91,121,102,46,82,195,53,18,11,165,61 };

    Solution solution;

    vector<int> result = solution.maxSlidingWindow(v1, 35);
}

