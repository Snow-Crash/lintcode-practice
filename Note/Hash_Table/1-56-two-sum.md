# Two Sum

<https://leetcode.com/problems/two-sum/>
<https://www.lintcode.com/problem/two-sum/description>

## Key points

Given target t, find a and b such they add up to t.

Use a hash table to establish the relation. t - a must be in the array. Therefore, loop over the array, for each number number, get t-a first, the difference is b. Use b as key, and loop index, which is the index of a as value.

## Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> m;

        int i = 0;

        for (; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (m.count(nums[i]) == 0)
                m[temp] = i;
            else
                break;
        }

        return { m[nums[i]], i };
    }
};
```
