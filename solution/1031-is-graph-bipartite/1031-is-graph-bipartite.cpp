// 1031-is-graph-bipartite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param graph: the given undirected graph
     * @return:  return true if and only if it is bipartite
     */
    bool isBipartite(vector<vector<int>>& graph) {
        // Write your code here

        vector<int> colors(graph.size(), 0);

        for (int i = 0; i != graph.size(); i++)
        {

            if (colors[i] == 0)
            {
                if (dfs(graph, i, 1, colors) == false)
                    return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>>& graph, int node, int color, vector<int>& colors)
    {
        if (colors[node] != 0 && colors[node] != color)
            return false;
        
        if (colors[node] != 0 && colors[node] == color)
            return true;

        colors[node] = color;

        for (int i = 0; i != graph[node].size(); i++)
        {
            int neighbor = graph[node][i];
            int next_color = -1 * color;

            if (dfs(graph, neighbor, next_color, colors) == false)
                return false;
        }

        return true;
    }
};

int main()
{

    vector<vector<int>> graph{ {1, 3}, {0, 2}, {1, 3}, {0, 2} };

    Solution solution;

    bool result = solution.isBipartite(graph);


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
