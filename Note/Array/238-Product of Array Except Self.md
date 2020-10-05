# 238.Product of Array Except Self

https://leetcode.com/problems/product-of-array-except-self

## Summary

Given array of length L, use two array 'left' and 'right' to record the accumulated product on left side and right side. left[i] = prod_{0 <= j < i}arr[j], right[i] = prod_{i < j <= L-1} arr[j].

## Solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Note that for the first element, its left side accumulated product is 1 because there is not element on its left side.
        // Similarly, for the last element, its right side accumulated product is 1, as there is no element on its right side.
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        // idx start from 1, there is no need to compute the left side accumulated product of 0th element.
        for (int i = 1; i < nums.size(); i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // idx start form L-2.
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(left[i] * right[i]);
        }

        return res;
    }
};
```

## Reference

https://leetcode.com/problems/product-of-array-except-self/solution/