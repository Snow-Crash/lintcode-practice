# 56.Merge Intervals

<https://leetcode.com/problems/merge-intervals>

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result {intervals[0]};

        for(int i = 1; i < intervals.size(); i++)
        {
            int curr_begin = intervals[i][0];
            int curr_end = intervals[i][1];

            int prev_begin = result.back()[0];
            int prev_end = result.back()[1];

            // overlap
            if (curr_begin <= prev_end)
            {
                // if current interval is covered by previous interval
                if ( curr_end <= prev_end)
                    continue;
                else
                {
                    result.back()[1] = curr_end;
                }
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }

        return result;

    }

    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] < v2[0];
    }
};
```
