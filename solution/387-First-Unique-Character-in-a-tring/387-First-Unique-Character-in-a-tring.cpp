// 387-First-Unique-Character-in-a-tring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char, int> count;
        
        queue<int> q;


        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            count[c]++;

            if (count[c] == 1)
            {
                q.push(i);
                continue;
            }
            
            while (q.empty() == false && count[s[q.front()]] > 1)
            {
                q.pop();
            }
        }

        if (q.empty() == true)
            return -1;
        else
            return q.front();
    }
};

int main()
{
    string s1 = "leetcode";

    string s2 = "loveleetcode";

    Solution solution;

    int res = solution.firstUniqChar(s2);
}
