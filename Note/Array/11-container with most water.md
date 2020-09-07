## Container With Most Water

<https://leetcode.com/problems/container-with-most-water>

    <https://www.lintcode.com/problem/container-with-most-water/description>

## Key points

Use two pointer i and j, one starts from 0 and another starts from size-1. Both pointers move to the other size. The area is given by:

```cpp
(j-i)*min(height[i],height[j]);
```

if height[i] <= height[j], move i to right by 1 position. Otherwise move j to left by 1 position.

## Solution

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size()-1;

        int res = 0;

        while(i < j)
        {
            res = max(res, min(height[i], height[j])*(j-i));

            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};
```

## Related Problems

Trapping Rain Water

<https://leetcode.com/problems/trapping-rain-water/>

## Reference

<http://www.cnblogs.com/grandyang/p/4455109.html>
