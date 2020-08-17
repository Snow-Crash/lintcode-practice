// 171-Anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string>& strs) {
        // write your code here

        unordered_map<string, vector<int>> lut;

        vector<int> visited(strs.size(), 0);

        vector<string> res;

        for (int i = 0; i != strs.size(); i++)
        {
            vector<int> cnt(26, 0);
            for (char c : strs[i])
            {
                cnt[c - 'a'] ++;
            }

            lut[strs[i]] = cnt;
        }

        for (int i = 0; i < strs.size() - 1; i++)
        {
            if (visited[i] == 1)
                continue;

            for (int j = i + 1; j < strs.size(); j++)
            {
                if (visited[j] == 1)
                    continue;
                if (lut[strs[i]] == lut[strs[j]])
                {

                    if (visited[i] == 0)
                        res.push_back(strs[i]);
                    
                    if (visited[j] == 0)
                        res.push_back(strs[j]);

                    visited[i] = 1;
                    visited[j] = 1;


                }
            }

        }

        return res;

    }

//    void dfs(vector<string>& strs, int pos, vector<string>& res, unordered_map<string, vector<int>>& lut,
//        vector<int>& visited)
//    {
//
//        if (lut[strs[source]] == lut[strs[target]])
//        {
//            res.push_back(strs[target]);
//            visited[target] = 1;
//
//            if (visited[source] == 0)
//            {
//                visited[source] = 1;
//                res.push_back(strs[source]);
//            }
//        }
//
//        if ()
//
//        for (int i = target + 1; i < strs.size(); i++)
//        {
//            if (visited[i] == 1)
//                continue;
//
//            if (str.size() != strs[i].size())
//                continue;
//
//            dfs(strs, str, source, i, res, lut, visited);
//        }
//
//    }
};

int main()
{
    vector<string> s1{ "tea","and","ate","eat","den" };

    vector<string> s2{ "tea","","eat","","tea","" };

    Solution solution;

    vector<string> res = solution.anagrams(s1);
}