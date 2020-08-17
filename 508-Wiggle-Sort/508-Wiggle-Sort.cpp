// 508-Wiggle-Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int>& nums) {
        // write your code here

        quicksort(nums, 0, nums.size() - 1);

        for (int i = 1; i + 1 < nums.size(); i += 2)
        {
            swap(nums[i], nums[i + 1]);
        }
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
    }
};

int main()
{
    vector<int> numbers{ 3,5,2,1,6,4 };

    Solution solution;

    solution.wiggleSort(numbers);
}

