// 139-Subarray-Sum-Closest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int>& nums) {
        // write your code here

        vector<int> sum;
        vector<int> idx;

        int acc = 0;
        for (int i = 0; i != nums.size(); i++)
        {
            acc += nums[i];
            sum.push_back(acc);
            idx.push_back(i);
        }

        quicksort(sum, idx, 0, sum.size() - 1);

        int min_diff = INT_MAX;
        int start = 0;
        int end = 0;

        for (int i = 0; i != sum.size() - 1; i++)
        {
            int diff = abs(sum[i + 1] - sum[i]);
            if (diff < min_diff)
            {
                start = idx[i];
                end = idx[i + 1];
                min_diff = diff;
            }
        }

        if (start < end)
            return vector<int> {start + 1, end};
        else if (start == end)
            return vector<int> {start, end};
        else
            return vector<int> {end + 1, start};

    }

    void quicksort(vector<int>& numbers, vector<int>& idx, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = numbers[left];
        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (numbers[i] > pivot && numbers[j] < pivot)
            {
                swap(numbers[i], numbers[j]);
                swap(idx[i], idx[j]);
            }


            if (numbers[i] <= pivot)
                i++;

            if (numbers[j] >= pivot)
                j--;
        }

        swap(numbers[j], numbers[left]);
        swap(idx[j], idx[left]);


        quicksort(numbers, idx, left, j - 1);
        quicksort(numbers, idx, j + 1, right);
    }
};

class Solution2 {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int>& nums) {
        // write your code here

        vector<pair<int, int>> prefixsum;

        int acc = 0;
        for (int i = 0; i != nums.size(); i++)
        {
            acc += nums[i];
            prefixsum.push_back({ acc, i });
        }

        prefixsum.insert(prefixsum.begin(), { 0, -1 });

        sort(prefixsum.begin(), prefixsum.end());
        int min_diff = INT_MAX;
        int start = 0;
        int end = 0;

        for (int i = 0; i != prefixsum.size() - 1; i++)
        {
            int diff = abs(prefixsum[i + 1].first - prefixsum[i].first);
            if (diff < min_diff)
            {
                start = prefixsum[i].second;
                end = prefixsum[i + 1].second;
                min_diff = diff;
            }
        }

        if (start < end)
            return vector<int> {start + 1, end};
        else if (start == end)
            return vector<int> {start, end};
        else
            return vector<int> {end + 1, start};

    }
};

int main()
{
    Solution2 solution;

    vector<int> numbers{ 3,-3,5 };

    solution.subarraySumClosest(numbers);
}
