# Campus Bikes

<https://www.lintcode.com/problem/campus-bikes/description>

## Solution 1

Correct but, but time out. Reference:
1 https://blog.csdn.net/qq_36754149/article/details/102498965

2. <https://www.1point3acres.com/bbs/thread-536720-1-1.html>

```cpp
class Solution {
public:
    /**
     * @param workers: workers' location
     * @param bikes: bikes' location
     * @return: assign bikes
     */

    struct comp
    {
        bool operator() (vector<int> &a, vector<int> &b)
        {
            if (a[0] == b[0])
            {
                if (a[1] == b[1])
                    return a[2] > b[2];
                return a[1] > b[1];
            }
            return a[0] > b[0];
        }
    };

    vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        // write your code here

        vector<vector<int>> dist;

        priority_queue<vector<int>, vector<vector<int>>, comp> q;

        for(int i = 0; i != workers.size(); i++)
        {
            for(int j = 0; j != bikes.size(); j++)
            {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                vector<int> tuple {d, i, j};
                q.push(tuple);
            }
        }

        vector<int> worker_assigned (workers.size(), 0);
        vector<int> bike_assigned (bikes.size(), 0);

        vector<int> result (workers.size(), 0);

        while(q.empty() == false)
        {
            vector<int> tmp = q.top();
            int d = tmp[0];
            int w = tmp[1];
            int b = tmp[2];

            if (worker_assigned[w] == 0 && bike_assigned[b] == 0)
            {
                result[w] = b;
                worker_assigned[w] = 1;
                bike_assigned[b] =1;
            }

            q.pop();
        }

        return result;
    }
};
```

## Solution 2

## Solution 3

KM algorithm
