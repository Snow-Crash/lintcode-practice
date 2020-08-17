// 5-kth-largest-element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int>& nums) {
        // write your code here


        int begin = 0;
        int end = nums.size() - 1;

        while (true)
        {
            int boundary = sort(nums, begin, end);

            if (boundary == n - 1)
                return nums[boundary];

            if (boundary < n)
            {
                end = boundary - 1;
            }
            else if (boundary > n)
            {
                begin = boundary + 1;
            }
        }
    }

    int sort(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
            return begin;

        int pivot = nums[begin];

        int i = begin + 1;
        int j = end;

        while (i <= j)
        {
            if (nums[i] < pivot && nums[j] > pivot)
                swap(nums[i], nums[j]);


            if (nums[i] >= pivot)
                i++;

            if (nums[j] <= pivot)
                j--;
        }

        swap(nums[begin], nums[j]);

        return j;
    }
};

int main()
{

    vector<int> nums{ 1, 3, 4, 2 };

    Solution solution;

    int result = solution.kthLargestElement(1, nums);


    std::cout << "Hello World!\n";
}
