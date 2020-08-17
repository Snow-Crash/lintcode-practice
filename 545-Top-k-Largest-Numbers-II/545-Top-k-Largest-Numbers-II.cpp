// 545-Top-k-Largest-Numbers-II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /*
    * @param k: An integer
    */Solution(int k) {
    // do intialization if necessary

        top_k = k;
    }

    int top_k;
    priority_queue<int, vector<int>, greater<int>> q;

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here

        q.push(num);
        if (q.size() > top_k)
            q.pop();

    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here

        vector<int> result;

        for (int i = 0; (i != top_k) && (q.empty() == false); i++)
        {
            result.push_back(q.top());
            q.pop();
        }

        for (int i = 0; i != result.size(); i++)
            q.push(result[i]);

        return vector<int>(result.rbegin(), result.rend());
    }
};

int main()
{
    Solution solution(3);

    solution.add(3);
    solution.add(10);
    vector<int> v1 = solution.topk();
    solution.add(1000);
    solution.add(-99);
    vector<int> v2 = solution.topk();
    solution.add(4);
    vector<int> v3 = solution.topk();
    solution.add(100);
    vector<int> v4 = solution.topk();
}

