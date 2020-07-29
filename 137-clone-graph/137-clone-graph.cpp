// 137-clone-graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/clone-graph/description
// https://www.cnblogs.com/grandyang/p/4267628.html

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;

        dfs(node, map);

        return map[node];
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map)
    {
        if (node == NULL)
            return NULL;

        if (map.find(node) == map.end())
        {
            UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
            map[node] = new_node;

            for (int i = 0; i != node->neighbors.size(); i++)
            {
                UndirectedGraphNode* neighbor = node->neighbors[i];

                UndirectedGraphNode* new_neighbor = dfs(neighbor, map);

                new_node->neighbors.push_back(new_neighbor);
            }
            return new_node;
        }
        else
        {
            return map[node];
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
