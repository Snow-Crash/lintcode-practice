// quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://blog.csdn.net/MoreWindows/article/details/6684558
// https://juejin.im/post/5e9aa58b6fb9a03c791702ea#heading-12
class quicksort1
{
public:

    void sort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = nums[left];

        int i = left;
        int j = right;

        while (i < j)
        {
            while (i < j && nums[j] >= pivot)
                j--;

            // swap nums[i] and nums[j] also works
            nums[i] = nums[j];

            while (i < j && nums[i] <= pivot)
                i++;

            // swap nums[i] and nums[j] also works
            nums[j] = nums[i];
        }

        nums[i] = pivot;

        sort(nums, i + 1, right);
        sort(nums, left, i - 1);
    }
};

// ref: https://juejin.im/post/5e9aa58b6fb9a03c791702ea#heading-12
class quicksort2
{
public:

    void sort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = nums[left];

        int i = left + 1;
        int j = right;

        while (i < j)
        {

            while (nums[j] >= pivot && i < j)
            {
                j--;
            }

            while (nums[i] <= pivot && i < j)
            {
                i++;
            }

            //if (i < j)
                swap(nums[i], nums[j]);
        }

        if (nums[left] > nums[j])
            swap(nums[left], nums[j]);

        sort(nums, left, i - 1);
        sort(nums, i + 1, right);
    }

};

// https://www.cnblogs.com/grandyang/p/4539757.html
class quicksort3
{
public:
    void sort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;

        int pivot = nums[left];

        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (nums[i] > pivot && nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
            }

            if (nums[i] <= pivot)
                i++;

            if (nums[j] >= pivot)
                j--;
        }

        swap(nums[left], nums[j]);

        sort(nums, left, j - 1);
        sort(nums, j+1, right);
    }
};


int main()
{
    vector<int> nums1{ 5, 1, 9, 6, 6, 7, 11, 5, 3, 8, 4 };

    quicksort1 qs;

    qs.sort(nums1, 0, nums1.size() - 1);

}