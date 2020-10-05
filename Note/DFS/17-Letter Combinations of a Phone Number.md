# 17. Letter Combinations of a Phone Number

<https://leetcode.com/problems/letter-combinations-of-a-phone-number/>

## Summary

A typical DFS, recursion + backtrack.

## Solution

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        unordered_map<int, vector<char>> dict;

        char c = 'a';

        for (int i = 2; i <= 9; i++)
        {
            if (i <= 6 || i == 8)
            {
                vector<char> chars;
                for (int j = 0; j < 3; j++)
                {
                    chars.push_back(c);
                    c++;
                }
                dict[i] = chars;
            }
            else if (i == 7 || i == 9)
            {
                vector<char> chars;
                for (int j = 0; j < 4; j++)
                {
                    chars.push_back(c);
                    c++;
                }
                dict[i] = chars;
            }
        }

        vector<string> result;
        string path = "";
        int depth = 0;

        int curr_digit = digits[depth] - '0';
        for (int i = 0; i < dict[curr_digit].size(); i++)
        {
            char curr = dict[curr_digit][i];
            dfs(dict, digits, result, path + curr, depth + 1);
        }

        return result;

    }

    void dfs(unordered_map<int, vector<char>>& dict, string& digits, vector<string>& result, string path, int depth)
    {
        if (depth == digits.size())
        {
            result.push_back(path);
            return;
        }

        int curr_digit = digits[depth] - '0';
        for (int i = 0; i < dict[digits[depth]-'0'].size(); i++)
        {
            char curr = dict[curr_digit][i];
            dfs(dict, digits, result, path + curr, depth + 1);
        }
    }
};

```
