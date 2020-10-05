# 215-Kth Largest Element in an Array

<https://leetcode.com/problems/kth-largest-element-in-an-array/>

## Summary

Two approaches. 1. Sort the array. 2. Use a min heap; break when the heap size is nums.size() - k;

## Solution 1

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int> >pq;

        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);

            if (pq.size()>k)
                pq.pop();
        }

        return pq.top();
    }
};
```

## Solution 2

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sortArr(nums, 0, nums.size()-1);

        return nums[nums.size()-k];
    }

    void sortArr(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int p = nums[left];

        int i = left + 1;
        int j = right;

        while(i <= j)
        {
            if (nums[i] > p && nums[j] < p)
                swap(nums[i], nums[j]);

            if (nums[i] <= p)
                i++;

            if (nums[j] >= p)
                j--;
        }

        swap(nums[left], nums[j]);

        sortArr(nums, left, j-1);
        sortArr(nums, j+1, right);
    }
};
```


