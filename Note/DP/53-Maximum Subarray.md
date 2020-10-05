# 53. Maximum Subarray

<https://leetcode.com/problems/maximum-subarray/>

## Summary

### DP

#### DP table

dp[i] represents the maximum sub array ends with ith element in array. Initialize dp as 0.

#### State transition

dp[i+1] is dependent on dp[i], there are two cases:

1. The previous sub array ends with ith elements and i+1 th element form a new sub array, new sub array's sum = dp[i] + array[i+1].

2. Start from i+1 element, a new sub array is formed, this sub array only contains array[i+1].

The state transition is:

```cpp
dp[i] = max(dp[i-1]+nums[i], nums[i]);
```

We need to compare dp[i] + array[i+1] and array[i+1], in other words, we have to sub arrays 1) array[some index : i] and 2) array[i+1]. We select the largest one and assign it to dp[i+1].

### Greedy

Idea is similar as DP. Use a variable currSum to record the maximum sum of sub array ends with ith element. Loop over the array, at each position, there will be two cases, the previous sub array ends with ith element is larger, or a new sub array, which only contains array[i] is larger. currSum will be the larger one. And every iteration, update maxSum if currSum > maxSum.


## Solution 1

DP

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];

        int maxSum = 0;

        for(int i = 1; i < nums.size();i++)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);

            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};
```

## Solution 2

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;

        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);

            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
```
