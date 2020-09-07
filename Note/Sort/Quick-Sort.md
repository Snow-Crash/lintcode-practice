# Quick Sort

## Quick sort version 1

```cpp
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
```

### Condition analysis

While loop stops when i==j, i is the boundary. This version does not swap values, instead, it overwrites values. We can image that at the beginning of the function, pivot is removed, therefore, nums[0] is a blank, then the while loop moves values iteratively. Every time it moves a value from j to i, there leaves a blank at j, this blank will be filled  by next move. When the loops stops, there isa blank at i, since nums[0], which is the povot, has already been overwriten in the beginning. We need to assign pivot to nums[i].

## Quick sort version 2

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
                swap(nums[i], nums[j]);
        }

        if (nums[left] > nums[j])
            swap(nums[left], nums[j]);

        sort(nums, left, i - 1);
        sort(nums, i + 1, right);
    }
};

int main()
{
    vector<int> nums1{ 5, 1, 9, 6, 7, 11, 5, 3, 8, 4 };

    quicksort2 qs;

    qs.sort(nums1, 0, nums1.size() - 1);
}
```

### Condition analysis

The while loop stops when i==j. After the while loop stops, value from 1 to i are no larger than pivot, and values from j to the end are not less than pivot. Therefore, position i(j) is the boundary. Since nums[0], which is the pivot has not been compared with nums[j] (becasue the loops stops when i==j, there is no change to compare them), therefore, after the while loop, it is necessary to compare nums[0] with nums[j], and determine whether swap. In this case, j is the boundary. Therefore, pass left, j-1 and j+1, right to next function.

## Quick sort version 3

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
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
    vector<int> nums1{ 5, 1, 9, 6, 7, 11, 5, 3, 8, 4 };

    quicksort3 qs;

    qs.sort(nums1, 0, nums1.size() - 1);

}
```

### Condition analysis

In the last iteration of the while loop, we have while condition: i == j. There will be following cases happen in the while loop body:

1. nums[i]<=pivot is true, nums[j] >= pivot is true
In this case, nums[i]== nums[j] == pivot. Therefore, i will increase by 1, and j will decrease by 1, such that the new j points to a value which is no larger than pivot and new i points to a value which is no less than pivot. After the last iteration, pivot is at nums[0],  and previous iterations of while loop have guaranteed that nums[1] to nums[j] are not larger than pivot, and nums[i] to the end of array are not less than pivot, therefore, the jth position will be boundary. After swap nums[j] and nums[0], num[0] to nums[j-1] are not greater than nums[j].
2. nums[i] <= pivot is true, nums[j] >= pivot is false
In this case, nums[i] == nums[j] < pivot. i will increase by 1 and j remains unchanged. Previous loops have guaranteed that all values after position j are not less than pivot, values from 1 to j - 1 are less than pivot. Therefore j is still the boundary. Since pivot is at position 0 after the last loop, we need to swap nums[0] and nums[j].
3. nums[i] <= pivot is false, nums[j] >= pivot is true
In this case, nums[i] == nums[j] > pivot. j will increase by 1, i remains unchanged.  Now values in [1, j-1] are not larger than pivot, values in [i, nums.size()-1] are larger than pivot (). j is still the boundary.
Summary
After the while loop stops, all values from 1 to j-1 are not larger than pivot, values from [j+1, nums.size()-1] are not less than pivot. j is the position where the pivot shoule be, nums[j] is not larger than pivot, therefore, after the while loop, no matter in what cases, it is necessary to swap nums[0] and nums[j]

## References

<https://greyireland.gitbook.io/algorithm-pattern/ji-chu-suan-fa-pian/sort>

<https://juejin.im/post/5e9aa58b6fb9a03c791702ea#heading-0>

<https://wiki.jikexueyuan.com/project/easy-learn-algorithm/fast-sort.html>

<http://data.biancheng.net/view/117.html>

<https://www.cnblogs.com/grandyang/p/4539757.html>

<http://www.blogjava.net/killme2008/archive/2010/09/08/quicksort_optimized.html>
