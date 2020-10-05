# 207.Course Schedule

<https://leetcode.com/problems/course-schedule>

## Summary

Topological sort. Use a counter to counter nodes that have been visited. If there is loop inside the graph, the queue will be empty but some nodes are still not visited. Therefore, use a counter to count number of visited node. If it is not equal to course number, there must be loop.

## Solution

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if (numCourses == 0)
            return true;

        queue<int> q;

        vector<int> indegree(numCourses, 0);

        vector<vector<int>> graph(numCourses, vector<int>());

        // build the graph
        // and also count in-degree of all nodes
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[course]++;

            graph[pre].push_back(course);
        }

        // put nodes that have 0 in-degree into queue
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        // counter to count number of visited nodes
        int cnt = 0;

        // iterate the graph
        while (q.empty() == false)
        {
            int curr = q.front();
            q.pop();

            // count visited nodes

            cnt++;
            for (int i = 0; i < graph[curr].size(); i++)
            {
                int neighbor = graph[curr][i];

                // after visiting a node, 'remove' it from graph, this is done by decreasing  its neighbors' in-degree by 1
                indegree[neighbor]--;

                // when a neighbor's in-degree is 0, push into queue
                // if a loop exists, there will be no nodes have 0 in-degree, thus the while loop will break before visiting all nodes in the graph. Hence cnt will not equal to node number
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return cnt == numCourses ? true : false;
    }
};
```
