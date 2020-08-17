// 1244-Minimum-Genetic-Mutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * @param start:
     * @param end:
     * @param bank:
     * @return: the minimum number of mutations needed to mutate from "start" to "end"
     */
    int minMutation(string& start, string& end, vector<string>& bank) {
        // Write your code here

        // vector<char> elements {'A', 'C', 'G', 'T'};
        // unordered_set<string> bank_set;

        // for (int i = 0; i != bank.size(); i++)
        // {
        //     bank_set.insert(bank[i]);
        // }

        // unordered_map<string, int> distance;

        // distance[start] = 0;

        // queue<string> q;

        // q.push(start);

        // while(q.empty() == false)
        // {
        //     string current = q.front();
        //     q.pop();

        //     //replace every character
        //     for (int i = 0; i != current.size(); i++)
        //     {
        //         // string next = current;
        //         for (int j = 0; j != elements.size(); j++)
        //         {
        //             string next = current;
        //             next[i] = elements[j];

        //             if (bank_set.find(next) != bank_set.end() && next == end)
        //             {
        //                 return distance[current] + 1;
        //             }

        //             if (bank_set.find(next) != bank_set.end() && distance.find(next) == distance.end())
        //             {
        //                 q.push(next);
        //                 distance[next] = distance[current] + 1;
        //             }
        //         }
        //     }
        // }

        // return -1;

        // return solution1(start, end, bank);

        return solution2(start, end, bank);

    }

    int solution1(string& start, string& end, vector<string>& bank)
    {

        vector<char> elements{ 'A', 'C', 'G', 'T' };
        unordered_set<string> bank_set;

        for (int i = 0; i != bank.size(); i++)
        {
            bank_set.insert(bank[i]);
        }

        unordered_map<string, int> distance;

        distance[start] = 0;

        queue<string> q;

        q.push(start);

        while (q.empty() == false)
        {
            string current = q.front();
            q.pop();

            //replace every character
            for (int i = 0; i != current.size(); i++)
            {
                // string next = current;
                for (int j = 0; j != elements.size(); j++)
                {
                    string next = current;
                    next[i] = elements[j];

                    if (bank_set.find(next) != bank_set.end() && next == end)
                    {
                        return distance[current] + 1;
                    }

                    if (bank_set.find(next) != bank_set.end() && distance.find(next) == distance.end())
                    {
                        q.push(next);
                        distance[next] = distance[current] + 1;
                    }
                }
            }
        }

        return -1;
    }

    int solution2(string& start, string& end, vector<string>& bank)
    {
        vector<char> elements{ 'A', 'C', 'G', 'T' };
        unordered_set<string> bank_set;

        for (int i = 0; i != bank.size(); i++)
        {
            bank_set.insert(bank[i]);
        }

        unordered_map<string, int> distance;
        unordered_set<string> visited;

        distance[start] = 0;

        queue<string> q;

        q.push(start);

        int level = 0;

        while (q.empty() == false)
        {
            int q_size = q.size();

            for (int i = 0; i != q_size; i++)
            {
                string current = q.front();
                q.pop();
                for (int j = 0; j != start.size(); j++)
                {
                    for (int k = 0; k != elements.size(); k++)
                    {
                        string next = current;
                        next[j] = elements[k];

                        if (bank_set.find(next) != bank_set.end() && next == end)
                        {
                            return level + 1;
                        }

                        if (bank_set.find(next) != bank_set.end() && visited.find(next) == visited.end())
                        {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }

            level = level + 1;
        }

        return -1;
    }

};

int main()
{
    Solution solution;

    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank{ "AAAACCCC", "AAACCCCC", "AACCCCCC" };

    solution.minMutation(start, end, bank);
}