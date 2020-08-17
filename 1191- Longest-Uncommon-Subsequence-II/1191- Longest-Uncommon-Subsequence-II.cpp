// 1191- Longest-Uncommon-Subsequence-II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param strs: List[str]
     * @return: return an integer
     */
    int findLUSlength(vector<string>& strs) {
        // write your code here

        unordered_set<string> strset;

        sort(strs.begin(), strs.end(), comp);


        for (int i = 0; i != strs.size(); i++)
        {
            if (i != strs.size() - 1 || strs[i] != strs[i + 1])
            {
                bool issubstr = false;
                for (auto it = strset.begin(); it != strset.end(); it++)
                {
                    string str = *it;
                    issubstr = check(str, strs[i]);

                    if (issubstr)
                        break;
                }

                if (issubstr == false)
                    return strs[i].size();

            }

            strset.insert(strs[i]);

        }

        return -1;

    }

    static bool comp(string& str1, string& str2)
    {
        return str1.size() > str2.size();
    }

    bool check(string& str, string& substr)
    {
        int j = 0;
        for (int i = 0; i != str.size(); i++)
        {
            if (str[i] == substr[j])
                j++;

            if (j == substr.size())
                break;
        }

        return j == substr.size();
    }
};

int main()
{

    vector<string> strs{ "aabbcc", "aabbcc","cb" };

    Solution solution;

    int result = solution.findLUSlength(strs);

}
