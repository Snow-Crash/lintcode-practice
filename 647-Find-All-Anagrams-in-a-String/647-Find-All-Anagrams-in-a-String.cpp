// 647-Find-All-Anagrams-in-a-String.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/find-all-anagrams-in-a-string/description

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string& s, string& p) {
        // write your code here

        unordered_map<char, int> p_map;
        unordered_map<char, int> s_map;

        vector<int> result;

        for (int i = 0; i != p.size(); i++)
        {
            p_map[p[i]]++;
        }

        int l = 0;
        int r = 0;

        for (; r < s.size(); r++)
        {
            char current = s[r];

            s_map[current]++;

            if (r - l + 1 > p.size())
            {
                s_map[s[l]]--;

                l++;
            }

            bool valid = true;

            for (auto it = p_map.begin(); it != p_map.end(); it++)
            {
                if (it->second != s_map[it->first])
                {
                    valid = false;
                    break;
                }
            }

            if (valid == true)
                result.push_back(l);
        }
        return result;
    }
};

int main()
{
    string s1 = "abab";
    string p1 = "ab";

    Solution solution;

    vector<int> result = solution.findAnagrams(s1, p1);

}
