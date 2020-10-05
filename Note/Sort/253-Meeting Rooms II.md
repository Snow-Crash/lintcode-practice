# 253. Meeting Rooms II

<https://leetcode.com/problems/meeting-rooms-ii/>

<https://www.cnblogs.com/grandyang/p/4606334.html>

## Solution 1

```cpp
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        priority_queue<int, vector<int>, greater<int>> q;

        sort(intervals.begin(), intervals.end());

        int result = INT_MIN;

        for(int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (q.size() == 0)
                q.push(end);
            else
            {
                if (q.top() <= start)
                {
                    q.pop();
                    q.push(end);
                }

                else
                    q.push(end);
            }

            int q_size = q.size();
            result = max(result, q_size);
        }

        return max(0, result);
    };

    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] < v2[0];
    }
};
```
