// 1201-Next-Greater-Element-II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array
     * @return: the Next Greater Number for every element
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Write your code here

        if (nums.size() == 0)
            return {};

        vector<int> res(nums.size(), -1);
        stack<pair<int, int>> s;

        int i = 0;

        int trip_count = 0;

        while (true)
        {
            int current = nums[i];

            if (s.empty() == true)
            {
                s.push({ current,i });
            }
            else
            {
                while (s.empty() == false && current > s.top().first)
                {
                    res[s.top().second] = current;
                    s.pop();
                }

                if (trip_count == 0)
                    s.push({ current, i });
            }

            i += 1;

            if (i == nums.size())
            {
                i = 0;
                trip_count++;
            }

            if (trip_count == 2)
                break;

        }

        return res;
    }
};

int main()
{
    Solution solution;

    vector<int> n1{ 1,2,1 };
        
    vector<int> res = solution.nextGreaterElements(n1);
}
