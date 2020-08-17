// 536-Find-First-and-Last-Position-of-Element-in-Sorted-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param nums: the array of integers
     * @param target:
     * @return: the starting and ending position
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        // Write your code here.


        int start = bs(nums, target);
        int end = bs(nums, target + 1);

        // if (start == 0 && nums[start] != target)
        //     start =-1;

        // if (end == nums.size()-1 && nums[end] != target)
        //     end = -1;

        if (start == 0 && end == nums.size() - 1 && nums[start] != target && nums[end] != target)
            return { -1,-1 };


        // if (start == -1 || end == -1)
        //     return {-1,-1};

        // if (nums[start] != target)
        //     start ++;

        if (nums[end] != target)
            end--;

        return { start, end };
    }


    int bs(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;

            if (target <= nums[mid])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
};

int main()
{
    vector<int> v1{ 5,7,7,8,8,10 };

    Solution solution;

    vector<int> result = solution.searchRange(v1, 6);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
