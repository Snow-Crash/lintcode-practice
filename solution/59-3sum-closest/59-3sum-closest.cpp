// 59-3sum-closest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int>& numbers, int target) {
        // write your code here

        quicksort(numbers, 0, numbers.size() - 1);

        int size = numbers.size();

        int min_diff = INT_MAX;

        int result = INT_MAX;

        for (int i = 0; i != size - 2; i++)
        {
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;

            int l = i + 1;
            int r = numbers.size() - 1;

            while (l < r)
            {
                int sum = numbers[i] + numbers[l] + numbers[r];
                int diff = abs(target - sum);
                if (sum == target)
                    return sum;
                else if (sum < target)
                    l++;
                else
                    r--;

                if (diff < min_diff)
                {
                    min_diff = diff;
                    result = sum;
                }

            }
        }

        return min_diff;
    }

    void quicksort(vector<int>& numbers, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = numbers[left];

        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (numbers[i] > pivot && numbers[j] < pivot)
                swap(numbers[i], numbers[j]);

            if (numbers[i] <= pivot)
                i++;

            if (numbers[j] >= pivot)
                j--;
        }

        swap(numbers[left], numbers[j]);

        quicksort(numbers, left, j - 1);
        quicksort(numbers, j + 1, right);
    }
};

int main()
{
    vector<int> numbers{ 2,7,11,15 };

    Solution solution;

    int result = solution.threeSumClosest(numbers, 20);
}