// 178-graph-valid-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/graph-valid-tree/description
// https://www.cnblogs.com/grandyang/p/5257919.html

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // write your code here
        vector<vector<int>> adj_list(n, vector<int>());

        vector<int> visited(n, 0);

        //create the adjacency list
        for (int i = 0; i != edges.size(); i++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        bool loop = dfs(0, -1, adj_list, visited);

        if (loop == false)
            return false;

        for (int i = 0; i != visited.size(); i++)
        {
            if (visited[i] != 1)
                return false;
        }

        return true;

    }
    bool dfs(int node, int pre, vector<vector<int>>& adjlist, vector<int>& visited)
    {
        // for(int i = 0; i != adjlist.size(); i++)
        // {
        //     for (int j = 0; i != adjlist[i].size(); j++)
        //     {

        //     }
        // }

        if (visited[node] == 1)
            return false;

        visited[node] = 1;

        for (int i = 0; i != adjlist[node].size(); i++)
        {
            int next = adjlist[node][i];

            if (next == pre)
                continue;

            bool valid = dfs(next, node, adjlist, visited);

            if (valid == false)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> edges = { {0, 1}, {0, 2}, {0, 3}, {1, 4} };

    bool result = solution.validTree(5, edges);

    std::cout << "Hello World!\n";
}
