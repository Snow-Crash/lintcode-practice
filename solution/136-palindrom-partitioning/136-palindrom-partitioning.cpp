// 136-palindrom-partitioning.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.lintcode.com/problem/palindrome-partitioning/description
// ref: https://www.cnblogs.com/grandyang/p/4270008.html

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string& s) {
        // write your code here

        vector<vector<string>> result;

        vector<string> partitions;

        dfs(result, partitions, s, 0);

        return result;
    }

    void dfs(vector<vector<string>>& result, vector<string>& partitions, string& s, int level)
    {
        if (level == s.size())
        {
            result.push_back(partitions);
            return;
        }

        for (int end = level; end != s.size(); end++)
        {
            bool valid = check(level, end, s);

            if (valid == false)
                continue;

            partitions.push_back(s.substr(level, end - level + 1));

            dfs(result, partitions, s, 1 + end);

            partitions.pop_back();
        }

    }

    bool check(int start, int end, string& s)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }


};

int main()
{
    Solution solution;
    
    string s = "bb";

    vector<vector<string>> result = solution.partition(s);

}