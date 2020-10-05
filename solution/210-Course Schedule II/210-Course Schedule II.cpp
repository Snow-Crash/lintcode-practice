// 210-Course Schedule II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses, vector<int>());

        vector<int> indegree(numCourses, 0);

        queue<int> q;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            graph[pre].push_back(course);
            indegree[course]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        int cnt = 0;

        while (q.empty() == false)
        {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            cnt++;

            for (int i = 0; i < graph[curr].size(); i++)
            {
                int neighbor = graph[curr][i];
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return cnt == numCourses ? result : vector<int>();

    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
