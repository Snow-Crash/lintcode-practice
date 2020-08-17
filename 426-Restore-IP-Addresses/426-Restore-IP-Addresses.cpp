// 426-Restore-IP-Addresses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // write your code here

        vector<vector<string>> result;

        vector<int> invalid(s.size(), 0);

        vector<string> path;

        for (int i = 0; i <= 2; i++)
        {
            dfs(s, 0, 0, i, path, invalid, result);
        }

        vector<string> res;

        for (int i = 0; i != result.size(); i++)
        {
            string str = "";
            for (int j = 0; j != result[i].size(); j++)
            {
                str = str + result[i][j];

                if (j != result[i].size() - 1)
                    str = str + ".";
            }

            res.push_back(str);
        }

        return res;

    }

    void dfs(string& s, int depth, int start, int end, vector<string>& path, vector<int>& invalid, vector<vector<string>>& result)
    {
        if (path.size() == 4 && end == s.size())
        {
            result.push_back(path);
            return;
        }

        //if (depth == 3 && end != s.size()-1)
        //{
        //    return;
        //}

        if (start >= s.size())
        {
            return;
        }

        if (end >= s.size())
            return;

        float remain_digits = s.size() - end - 1;
        float remain_seg = 4 - depth - 1;

        if ((remain_digits / remain_seg) > 3)
        {
            return;
        }

        if (invalid[start] == 1)
            return;

        string str = s.substr(start, end - start + 1);


        if (check(str) == false)
            return;

        for (int l = 0; l <= 2; l++)
        {
            path.push_back(str);
            dfs(s, depth + 1, end + 1, end + 1 + l, path, invalid, result);
            path.pop_back();
        }
    }

    bool check(string& str)
    {
        int val = stoi(str);

        if (str.size() == 2 && val < 10)
            return false;

        if (str.size() == 3 && val < 100)
            return false;

        if (val <= 255)
            return true;
        else return
            false;
    }
};

int main()
{
    string str = "25525511135";

    string str2 = "00000";

    string str3 = "010010";

    Solution solution;

    vector<string> result = solution.restoreIpAddresses(str3);
}
