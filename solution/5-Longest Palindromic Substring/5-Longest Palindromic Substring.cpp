// 5-Longest Palindromic Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.size() == 0)
            return "";

        int maxLen = 1;
        int start = 0;

        vector<vector<int>> table(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++)
        {
            table[i][i] = 1;

            for (int j = 0; j < i; j++)
            {
                if (s[j] == s[i])
                {
                    if (i == j+1)
                        table[j][i] = 1;
                    else if (i > j+1 && table[j + 1][i - 1] == 1)
                        table[j][i] = 1;
                }

                if (table[j][i] == 1 && i - j + 1 > maxLen)
                {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

class Solution2
{
public:

    string longestPalindrome(string s) {

        if (s.size() == 0)
            return "";

        string res = "";

        int maxLen = 1;

        for (int i = 0; i < s.size(); i++)
        {
            findPalindromicStr(s, i, i, maxLen, res);
            findPalindromicStr(s, i, i+1, maxLen, res);
        }

        return res;
    }

    void findPalindromicStr(string& s, int left, int right, int& maxLen, string &res)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        if (right - left - 1 > res.size())
        {
            maxLen = right - left - 1;
            res = s.substr(left + 1, maxLen);
        }
    }
};

int main()
{
    Solution solution;

    string s = "babad";
    string s2 = "ac";

    string res = solution.longestPalindrome(s2);

}
