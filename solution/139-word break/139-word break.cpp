// 139-word break.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> find(s.size(), -1);

        unordered_set<string> hashset(wordDict.begin(), wordDict.end());

        int res = recursion(s, 0, hashset, find);

        return res > 0 ? true : false;
    }

    int recursion(string& s, int start, unordered_set<string>& hastset, vector<int>& find)
    {
        if (start >= s.size())
            return 1;

        if (find[start] != -1)
            return find[start];

        for (int l = 1; l + start -1 < s.size(); l++)
        {
            if (hastset.count(s.substr(start, l)) > 0)
            {
                if (recursion(s, start + l, hastset, find) == 1)
                {
                    find[start] = 1;
                    return find[start];
                }
            }
        }

        find[start] = 0;

        return find[start];
    }
};

class Solution2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> find(s.size(), -1);

        unordered_set<string> hashset(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] == 1 && hashset.count(s.substr(j, i - j)) > 0)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp.back();
    }
};

class Solution3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), 0);

        unordered_set<string> check(wordDict.begin(), wordDict.end());

        return recursion(s, 0, check, dp);
    }

    bool recursion(string& s, int start, unordered_set<string>& check, vector<int>& dp)
    {
        if (start == s.size())
            return true;

        if (dp[start] == -1)
            return false;

        if (dp[start] == 1)
            return true;

        for (int len = 1; start + len <= s.size(); len++)
        {
            string substr = s.substr(start, len);

            if (check.count(substr) > 0)
            {
                if (recursion(s, start + len, check, dp))
                {
                    dp[start] = 0;
                    return true;
                }
            }   
        }
        dp[start] = -1;

        return false;
    }
};

int main()
{
    string s1 = "leetcode";

    vector<string> v1{ "leet", "code" };

    string s2 = "catsandog";

    vector<string> v2{ "cats", "dog", "sand", "and", "cat" };

    Solution3 solution;

    bool res = solution.wordBreak(s2, v2);
}