// 31-partition-array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int>& nums, int k) {
        // write your code here

        if (nums.size() == 0)
            return 0;

        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {

            while (i <= j && nums[i] < k)
                i++;

            while (i <= j && nums[j] >= k)
                j--;

            if (i < j)
                swap(nums[i], nums[j]);

        }

        return i;

    }
};

#include <iostream>

int main()
{
    vector<int> nums{ 7,7,9,8,6,6,8,7,9,8,6,6 };
    //vector<int> nums{ 3, 2, 1 };

    //vector<int> nums{ 9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9 };

    Solution solution;

    int result = solution.partitionArray(nums, 10);

}