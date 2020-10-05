// 49-Group-Anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];

            sort(str.begin(), str.end(), comp);

            m[str].push_back(strs[i]);
        }

        vector<vector<string>> res;

        for (auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second);
        }

        return res;
    }

    static bool comp(char& a, char& b)
    {
        if (a < b)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<string> strs{ "eat","tea","tan","ate","nat","bat" };

    Solution solution;

    vector<vector<string>> res = solution.groupAnagrams(strs);
}
