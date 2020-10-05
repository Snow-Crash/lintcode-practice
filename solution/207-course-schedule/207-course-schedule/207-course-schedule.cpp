// 207-course-schedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        if (numCourses == 0)
            return true;

        queue<int> q;

        vector<int> indegree(numCourses, 0);

        vector<vector<int>> graph(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[course]++;

            graph[pre].push_back(course);

        }

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while (q.empty() == false)
        {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < graph[curr].size(); i++)
            {
                int neighbor = graph[curr][i];

                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
            cnt++;
        }

        return cnt == numCourses ? true : false;
    }
};

int main()
{

    vector<vector<int>> v1{ {1,0} };

    Solution solution;

    bool res = solution.canFinish(2, v1);
}
