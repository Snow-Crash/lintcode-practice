// 1015-find-eventual-safe-states.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param graph: a 2D integers array
     * @return: return a list of integers
     */
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // write your code here

        int len = graph.size();

        vector<int> loop(len, 0);

        vector<int> color(len, 0);

        vector<int> path;

        // for (int i = 0; i != graph.size(); i++)
        // {
        //     for (int j = 0; j != graph[i].size(); j++)
        //     {
        //         dfs(graph, i, j, path, loop);
        //     }
        // }

        // for (int i = 0; i != graph.size(); i++)
        // {
        //         dfs2(graph, i, color, path, loop);
        // }

        vector<int> result;

        for (int i = 0; i != graph.size(); i++)
        {
            bool stable = dfs3(graph, i, color);

            if (stable == true)
                result.push_back(i);
        }



        // for(int i = 0; i != loop.size(); i++)
        // {
        //     if (loop[i] != 1)
        //         result.push_back(i);
        // }
        return result;

    }

    void dfs(vector<vector<int>>& graph, int start, int node, vector<int>& path, vector<int>& loop)
    {

        if (loop[node] == 1)
            return;

        int neighbor_num = graph[node].size();

        for (int i = 0; i != neighbor_num; i++)
        {
            if (start == graph[node][i])
            {
                for (int j = 0; j != path.size(); j++)
                {
                    int idx = path[j];
                    loop[idx] = 1;
                    loop[start] = 1;
                }
            }
            else
            {
                path.push_back(graph[node][i]);
                dfs(graph, start, graph[node][i], path, loop);
                path.pop_back();
            }
        }
    }

    void dfs2(vector<vector<int>>& graph, int node, vector<int>& color, vector<int>& path, vector<int>& loop)
    {
        // if current node is in dfs path
        if (color[node] == 1 || loop[node] == 1)
        {
            for (int i = 0; i != path.size(); i++)
            {
                loop[path[i]] = 1;
            }

            return;
        }

        color[node] = 1;

        for (int i = 0; i != graph[node].size(); i++)
        {
            int neighbor = graph[node][i];
            if (color[neighbor] == 2)
                continue;

            path.push_back(neighbor);
            dfs2(graph, neighbor, color, path, loop);
            path.pop_back();
        }

        color[node] = 2;
    }

    bool dfs3(vector<vector<int>>& graph, int node, vector<int>& color)
    {
        // 1 represents in current dfs stack,
        // so there is a loop
        if (color[node] == 1)
            return false;

        color[node] = 1;

        //
        for (int i = 0; i != graph[node].size(); i++)
        {
            int neighbor = graph[node][i];
            if (color[neighbor] == 2)
                continue;

            if (dfs3(graph, neighbor, color) == false)
                return false;
        }

        color[node] = 2;

        return true;
    }
};

int main()
{

    vector<vector<int>> graph{ {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {} };

    Solution solution;

    vector<int> result = solution.eventualSafeNodes(graph);

    std::cout << "Hello World!\n";
}
